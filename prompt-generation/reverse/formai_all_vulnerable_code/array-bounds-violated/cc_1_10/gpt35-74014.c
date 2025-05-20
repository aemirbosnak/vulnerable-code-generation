//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s destination_ip\n", argv[0]);
        exit(1);
    }

    int sockfd, clientfd, dstfd;
    struct sockaddr_in addr, client_addr, dst_addr;
    socklen_t client_len = sizeof(client_addr);

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Error opening socket");
    }

    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        error("Error binding socket");
    }

    if(listen(sockfd, 5) < 0) {
        error("Error listening on socket");
    }

    printf("HTTP Proxy server running on port %d...\n", PORT);

    while(1) {
        if((clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            error("Error accepting client connection");
        }
        printf("\nIncoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if((dstfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            error("Error opening destination socket");
        }

        memset(&dst_addr, 0, sizeof(dst_addr));
        dst_addr.sin_family = AF_INET;
        dst_addr.sin_addr.s_addr = inet_addr(argv[1]);
        dst_addr.sin_port = htons(80);

        if(connect(dstfd, (struct sockaddr *)&dst_addr, sizeof(dst_addr)) < 0) {
            error("Error connecting to destination server");
        }

        char buffer[BUF_SIZE];
        int bytes;

        if((bytes = recv(clientfd, buffer, BUF_SIZE, 0)) < 0) {
            error("Error receiving data from client");
        }
        buffer[bytes] = '\0';

        if(send(dstfd, buffer, bytes, 0) < 0) {
            error("Error sending data to destination server");
        }

        while(1) {
            if((bytes = recv(dstfd, buffer, BUF_SIZE, 0)) < 0) {
                error("Error receiving data from destination server");
            }
            if(bytes == 0) break;

            if(send(clientfd, buffer, bytes, 0) < 0) {
                error("Error sending data to client");
            }
        }

        close(clientfd);
        close(dstfd);
    }

    close(sockfd);

    return 0;
}