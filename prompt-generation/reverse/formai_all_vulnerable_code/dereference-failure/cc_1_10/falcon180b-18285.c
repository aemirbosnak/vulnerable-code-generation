//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: realistic
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
    char *ip_str;
    char buffer[BUF_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage:./ftp_client <IP address> <port number>\n");
        exit(1);
    }

    ip_str = argv[1];
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, ip_str, &server_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connected to FTP server\n");

    while (1) {
        printf("Enter command (quit to exit): ");
        fgets(buffer, BUF_SIZE, stdin);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n == -1) {
            printf("Error: send failed\n");
            exit(1);
        }

        memset(buffer, 0, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n == -1) {
            printf("Error: recv failed\n");
            exit(1);
        }

        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}