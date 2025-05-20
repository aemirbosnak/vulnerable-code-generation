//Falcon-180B DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void process_packet(char *packet) {
    char *token;
    char hostname[50];
    int port;
    sscanf(packet, "CONNECT %s:%d", hostname, &port);
    printf("Request to connect to %s:%d\n", hostname, port);
}

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket");
        exit(1);
    }
    bzero(&serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket");
        exit(1);
    }
    listen(sockfd, 3);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if (newsockfd < 0) {
            printf("Error accepting connection");
            exit(1);
        }
        while (1) {
            memset(buffer, '\0', BUFFER_SIZE);
            int n = recv(newsockfd, buffer, BUFFER_SIZE, 0);
            if (n <= 0) {
                printf("Connection closed");
                close(newsockfd);
                break;
            } else {
                process_packet(buffer);
            }
        }
    }
    return 0;
}