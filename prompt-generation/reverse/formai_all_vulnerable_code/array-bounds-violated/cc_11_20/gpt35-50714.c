//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, proxyfd, maxfd;
    char buffer[BUFFER_SIZE];
    ssize_t n;
    struct sockaddr_in proxy_addr, server_addr;
    fd_set readfds;

    if(argc != 4) {
        fprintf(stderr, "Usage: %s <proxy_port> <server_address> <server_port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sockfd, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    listen(sockfd, 5);

    printf("Proxy server listening on port %s...\n", argv[1]);

    while(1) {
        proxyfd = accept(sockfd, NULL, NULL);
        if(proxyfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Proxy connection established...\n");

        if((n = recv(proxyfd, buffer, BUFFER_SIZE, 0)) < 0) {
            perror("Error receiving data");
            exit(1);
        }

        buffer[n] = '\0';

        char *req = strtok(buffer, "\r\n");
        char *method = strtok(req, " ");
        char *path = strtok(NULL, " ");
        strtok(NULL, " ");
        char *host = strtok(NULL, "\r\n");
        strtok(NULL, "\r\n");

        char request[BUFFER_SIZE];
        sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", method, path, host);

        printf("The request client will see:\n%s\n", request);

        int serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if(serverfd < 0) {
            perror("Error creating socket");
            exit(1);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(argv[2]);
        server_addr.sin_port = htons(atoi(argv[3]));

        if(connect(serverfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
            perror("Error connecting to server");
            exit(1);
        }

        if(send(serverfd, request, strlen(request), 0) < 0) {
            perror("Error sending request to server");
            exit(1);
        }

        printf("Waiting for response...\n");

        FD_ZERO(&readfds);
        FD_SET(proxyfd, &readfds);
        FD_SET(serverfd, &readfds);
        maxfd = (proxyfd > serverfd) ? proxyfd : serverfd;

        while(select(maxfd+1, &readfds, NULL, NULL, NULL) > 0) {
            if(FD_ISSET(proxyfd, &readfds)) {
                if((n = recv(proxyfd, buffer, BUFFER_SIZE, 0)) < 0) {
                    perror("Error receiving data");
                    exit(1);
                }

                buffer[n] = '\0';

                if(send(serverfd, buffer, n, 0) < 0) {
                    perror("Error sending data to server");
                    exit(1);
                }
            }

            if(FD_ISSET(serverfd, &readfds)) {
                if((n = recv(serverfd, buffer, BUFFER_SIZE, 0)) < 0) {
                    perror("Error receiving data");
                    exit(1);
                }

                buffer[n] = '\0';

                if(send(proxyfd, buffer, n, 0) < 0) {
                    perror("Error sending data to client");
                    exit(1);
                }
            }

            FD_ZERO(&readfds);
            FD_SET(proxyfd, &readfds);
            FD_SET(serverfd, &readfds);
            maxfd = (proxyfd > serverfd) ? proxyfd : serverfd;
        }

        printf("Proxy connection closed...\n");

        close(serverfd);
        close(proxyfd);
    }

    close(sockfd);

    return 0;
}