//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int port;
    char *ip;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./ftp_client <IP address> <Port number> <Command>\n");
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    strcpy(buffer, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending command\n");
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            printf("Error receiving response\n");
            return 1;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}