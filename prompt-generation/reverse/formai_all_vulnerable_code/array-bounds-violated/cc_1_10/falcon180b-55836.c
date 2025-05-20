//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096
#define LISTENQ 10

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in addr;
    int addrlen = sizeof(addr);
    char buffer[MAXLINE];
    int n;

    // Create socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(1);
    }

    // Set options on socket
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind socket
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *)&addr, addrlen) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen on socket
    if (listen(listenfd, LISTENQ) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept connection
        if ((connfd = accept(listenfd, (struct sockaddr *)&addr, &addrlen)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s\n", inet_ntoa(addr.sin_addr));

        // Handle request
        do {
            n = recv(connfd, buffer, MAXLINE, 0);
            if (n <= 0) {
                break;
            }
            buffer[n] = '\0';

            printf("Request: %s\n", buffer);

            // Forward request to server
            send(connfd, buffer, strlen(buffer), 0);

        } while (1);

        // Close connection
        close(connfd);
    }

    return 0;
}