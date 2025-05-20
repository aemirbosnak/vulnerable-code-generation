//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 4096

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <listen-port> <server-host> <server-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *listen_port = argv[1];
    char *server_host = argv[2];
    char *server_port = argv[3];
    int sockfd, num_bytes;
    struct addrinfo hints, *res;
    struct sockaddr_storage client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    char buf[BUFSIZE];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, listen_port, &hints, &res) != 0) {
        fprintf(stderr, "getaddrinfo failed\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (true) {
        int client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_size);

        if (client_sockfd == -1) {
            perror("accept failed");
            continue;
        }

        if (fork() == 0) {
            close(sockfd);
            char *request = malloc(BUFSIZE);
            char *response = malloc(BUFSIZE);

            if (recv(client_sockfd, request, BUFSIZE, 0) == -1) {
                perror("recv failed");
                exit(EXIT_FAILURE);
            }

            struct addrinfo server_hints, *server_res;

            memset(&server_hints, 0, sizeof(server_hints));
            server_hints.ai_family = AF_UNSPEC;
            server_hints.ai_socktype = SOCK_STREAM;

            if (getaddrinfo(server_host, server_port, &server_hints, &server_res) != 0) {
                fprintf(stderr, "getaddrinfo failed\n");
                exit(EXIT_FAILURE);
            }

            int server_sockfd = socket(server_res->ai_family, server_res->ai_socktype, server_res->ai_protocol);

            if (server_sockfd == -1) {
                perror("socket failed");
                exit(EXIT_FAILURE);
            }

            if (connect(server_sockfd, server_res->ai_addr, server_res->ai_addrlen) == -1) {
                perror("connect failed");
                exit(EXIT_FAILURE);
            }

            if (send(server_sockfd, request, strlen(request), 0) == -1) {
                perror("send failed");
                exit(EXIT_FAILURE);
            }

            while ((num_bytes = recv(server_sockfd, response, BUFSIZE, 0)) > 0) {
                if (send(client_sockfd, response, num_bytes, 0) == -1) {
                    perror("send failed");
                    exit(EXIT_FAILURE);
                }
            }

            if (num_bytes == -1) {
                perror("recv failed");
                exit(EXIT_FAILURE);
            }

            free(request);
            free(response);
            close(client_sockfd);
            close(server_sockfd);
            exit(EXIT_SUCCESS);
        }

        close(client_sockfd);
    }

    return 0;
}