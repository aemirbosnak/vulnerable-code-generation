//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    /* Check if the correct number of arguments is provided */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen-port> <destination-host>:<destination-port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Parse the listen port and destination address */
    int listen_port = atoi(argv[1]);
    char *destination_host = strtok(argv[2], ":");
    int destination_port = atoi(strtok(NULL, ":"));

    /* Create the listening socket */
    int listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    /* Bind the listening socket to the specified port */
    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(listen_port);
    if (bind(listen_sockfd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    /* Listen for incoming connections */
    if (listen(listen_sockfd, SOMAXCONN) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    /* Main loop: accept connections, forward requests, and receive responses */
    while (1) {
        /* Accept an incoming connection */
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(listen_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        /* Create a socket to connect to the destination host */
        int destination_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (destination_sockfd == -1) {
            perror("socket");
            close(client_sockfd);
            continue;
        }

        /* Connect to the destination host */
        struct sockaddr_in destination_addr;
        memset(&destination_addr, 0, sizeof(destination_addr));
        destination_addr.sin_family = AF_INET;
        destination_addr.sin_addr.s_addr = inet_addr(destination_host);
        destination_addr.sin_port = htons(destination_port);
        if (connect(destination_sockfd, (struct sockaddr *)&destination_addr, sizeof(destination_addr)) == -1) {
            perror("connect");
            close(client_sockfd);
            close(destination_sockfd);
            continue;
        }

        /* Forward the HTTP request from the client to the destination host */
        char buf[MAX_BUF_SIZE];
        ssize_t nbytes;
        while ((nbytes = read(client_sockfd, buf, sizeof(buf))) > 0) {
            if (write(destination_sockfd, buf, nbytes) == -1) {
                perror("write");
                break;
            }
        }
        if (nbytes == -1) {
            perror("read");
            close(client_sockfd);
            close(destination_sockfd);
            continue;
        }

        /* Receive the HTTP response from the destination host and forward it to the client */
        while ((nbytes = read(destination_sockfd, buf, sizeof(buf))) > 0) {
            if (write(client_sockfd, buf, nbytes) == -1) {
                perror("write");
                break;
            }
        }
        if (nbytes == -1) {
            perror("read");
            close(client_sockfd);
            close(destination_sockfd);
            continue;
        }

        /* Close the sockets */
        close(client_sockfd);
        close(destination_sockfd);
    }

    /* Close the listening socket */
    close(listen_sockfd);

    return EXIT_SUCCESS;
}