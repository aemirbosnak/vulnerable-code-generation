//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <proxy-port> <server-ip>\n", argv[0]);
        return 1;
    }

    int proxy_port = atoi(argv[1]);
    char *server_ip = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in proxy_addr, server_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);
    if (bind(sockfd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    printf("Proxy server running on port %d...\n", ntohs(proxy_addr.sin_port));
    printf("Listening for incoming connections...\n");

    while (1) {
        int client_sockfd = accept(sockfd, NULL, NULL);
        if (client_sockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        char buffer[1024];
        int nread = recv(client_sockfd, buffer, sizeof(buffer), 0);
        if (nread < 0) {
            perror("Error reading from client");
            continue;
        }

        buffer[nread] = '\0';
        printf("Client request: %s\n", buffer);

        // Modify or intercept the request here

        buffer[nread] = '\0';
        printf("Proxy response: %s\n", buffer);
        send(client_sockfd, buffer, nread, 0);
        close(client_sockfd);
    }

    return 0;
}