//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <fcntl.h>

#define BUFSIZE 4096

/* Signal handler to handle SIGCHLD */
void zombie_killer(int num) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd, status;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buf[BUFSIZE];
     
    /* Create a socket for incoming connections */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    /* Set socket to reuse local address */
    int enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        perror("Error setting SO_REUSEADDR option");
        exit(EXIT_FAILURE);
    }
    
    /* Bind the socket to the given address and port */
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    /* Listen for incoming connections */
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    /* Register signal handler to handle SIGCHLD */
    signal(SIGCHLD, zombie_killer);

    printf("Listening on port %d...\n", atoi(argv[1]));

    while (1) {
        /* Accept incoming connections */
        client_sockfd = accept(sockfd, (struct sockaddr *) &client, &client_len);
        if (client_sockfd < 0) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }
        
        /* Fork a child process to handle the incoming connection */
        pid_t pid = fork();
        if (pid < 0) {
            perror("Error forking child process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            close(sockfd);

            /* Receive request from client */
            memset(buf, 0, BUFSIZE);
            int n = recv(client_sockfd, buf, BUFSIZE, 0);
            if (n < 0) {
                perror("Error receiving request from client");
                exit(EXIT_FAILURE);
            }

            /* Parse request */
            char method[10], url[50], http_version[10];
            sscanf(buf, "%s %s %s", method, url, http_version);

            /* Check if method is GET */
            if (strcmp(method, "GET") != 0) {
                perror("Unsupported method");
                exit(EXIT_FAILURE);
            }

            /* Parse URL */
            char *host, *port, *path, *pch;
            int is_ssl = 0;
            if (strncmp(url, "http://", 7) == 0) {
                host = url + 7;
            } else if (strncmp(url, "https://", 8) == 0) {
                is_ssl = 1;
                host = url + 8;
            } else {
                perror("Unsupported URL scheme");
                exit(EXIT_FAILURE);
            }
            pch = strchr(host, ':');
            if (pch == NULL) {
                port = is_ssl ? "443" : "80";
                path = strchr(host, '/');
            } else {
                port = pch + 1;
                path = strchr(pch + 1, '/');
            }
            if (path == NULL) {
                path = "/";
            }

            /* Resolve hostname */
            struct addrinfo hints, *res;
            int error;
            memset(&hints, 0, sizeof(hints));
            hints.ai_family = AF_INET;
            hints.ai_socktype = SOCK_STREAM;
            if ((error = getaddrinfo(host, port, &hints, &res))) {
                perror(gai_strerror(error));
                exit(EXIT_FAILURE);
            }

            /* Connect to server */
            int server_sockfd;
            if ((server_sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
                perror("Error creating socket for server");
                exit(EXIT_FAILURE);
            }
            if (connect(server_sockfd, res->ai_addr, res->ai_addrlen) < 0) {
                perror("Error connecting to server");
                exit(EXIT_FAILURE);
            }

            /* Send request to server */
            if (send(server_sockfd, buf, strlen(buf), 0) < 0) {
                perror("Error sending request to server");
                exit(EXIT_FAILURE);
            }

            /* Receive response from server */
            do {
                memset(buf, 0, BUFSIZE);
                n = recv(server_sockfd, buf, BUFSIZE, 0);
                if (n < 0) {
                    perror("Error receiving response from server");
                    exit(EXIT_FAILURE);
                } else if (n > 0) {
                    if (send(client_sockfd, buf, n, 0) < 0) {
                        perror("Error sending response to client");
                        exit(EXIT_FAILURE);
                    }
                }
            } while (n > 0);

            /* Close sockets */
            close(client_sockfd);
            close(server_sockfd);
            exit(0);
        } else {
            /* Parent process */
            close(client_sockfd);
        }
    }

    return 0;
}