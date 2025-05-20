//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, MAX_LINE);
        if (recv(sockfd, buffer, MAX_LINE, 0) == 0) {
            printf("Server disconnected\n");
            close(sockfd);
            return 0;
        }
        printf("%s", buffer);
    }

    return 0;
}