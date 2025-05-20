//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
// C Simple HTTP Proxy program
// Written in a scientific style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, listenfd, clientfd;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_len;

    // check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (sockfd < 0) {
        perror("socket() error");
        exit(1);
    }

    // bind to a local address and port
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind() error");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, SOMAXCONN) < 0) {
        perror("listen() error");
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        // accept a client connection
        client_len = sizeof(client_addr);
        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (clientfd < 0) {
            perror("accept() error");
            exit(1);
        }

        printf("Connection accepted: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // fork a child process to handle the client connection
        if (fork() == 0) {
            char buffer[BUF_SIZE];
            ssize_t num_bytes;

            // read the request from the client
            num_bytes = recv(clientfd, buffer, sizeof(buffer), 0);
            if (num_bytes < 0) {
                perror("recv() error");
                exit(1);
            }

            // extract the host and path from the request
            char *host = NULL;
            char *path = NULL;
            if (strstr(buffer, "GET ") != NULL) {
                char *start = strstr(buffer, "GET ") + 4;
                char *end = strstr(start, " HTTP/") - 1;
                path = (char *)malloc(sizeof(char) * (end - start + 1));
                strncpy(path, start, end - start + 1);
                path[end - start + 1] = '\0';
            }
            if (strstr(buffer, "Host: ") != NULL) {
                char *start = strstr(buffer, "Host: ") + 6;
                char *end = strstr(start, "\r\n");
                host = (char *)malloc(sizeof(char) * (end - start + 1));
                strncpy(host, start, end - start);
                host[end - start] = '\0';
            }

            // resolve the host name to an IP address
            struct hostent *hostname = gethostbyname(host);
            if (hostname == NULL) {
                fprintf(stderr, "Error: could not resolve host name %s\n", host);
                exit(1);
            }
            char *ip_addr = inet_ntoa(*((struct in_addr *)hostname->h_addr));

            // create a socket and connect to the remote server
            int serverfd = socket(AF_INET, SOCK_STREAM, 0);
            if (serverfd < 0) {
                perror("socket() error");
                exit(1);
            }
            memset(&serv_addr, 0, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
            serv_addr.sin_port = htons(80);
            if (connect(serverfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                perror("connect() error");
                exit(1);
            }

            // send the request to the remote server
            if (send(serverfd, buffer, num_bytes, 0) < 0) {
                perror("send() error");
                exit(1);
            }

            // forward the response back to the client
            while ((num_bytes = recv(serverfd, buffer, sizeof(buffer), 0)) > 0) {
                if (send(clientfd, buffer, num_bytes, 0) < 0) {
                    perror("send() error");
                    exit(1);
                }
            }

            // close the sockets and free the memory
            close(clientfd);
            close(serverfd);
            free(path);
            free(host);
            exit(0);
        }

        // close the client socket in the parent process
        close(clientfd);
    }

    // close the listening socket
    close(sockfd);

    return 0;
}