//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

struct sockaddr_in server_addr;
char buffer[BUFFER_SIZE];

void main(int argc, char *argv[]) {
    int sockfd, n;
    struct hostent *host;
    struct in_addr **addr_list;

    if (argc!= 3) {
        printf("Usage:./program <IP address> <port number>\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Invalid IP address.\n");
        exit(1);
    }

    addr_list = (struct in_addr **)host->h_addr_list;
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n == -1) {
            printf("Error: Failed to receive data.\n");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sockfd);
}