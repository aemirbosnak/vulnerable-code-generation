//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUF_SIZE];
    char recv_buffer[BUF_SIZE];

    if (argc < 3) {
        printf("Usage:./ftp_client <IP Address> <Port>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(send_buffer, 0, BUF_SIZE);
        memset(recv_buffer, 0, BUF_SIZE);

        printf("Enter command: ");
        fgets(send_buffer, BUF_SIZE, stdin);

        if (send(sockfd, send_buffer, strlen(send_buffer), 0) == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        if (recv(sockfd, recv_buffer, BUF_SIZE, 0) == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Response: %s\n", recv_buffer);
    }

    close(sockfd);
    return 0;
}