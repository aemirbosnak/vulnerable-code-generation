//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUF_SIZE];
    char recv_buffer[BUF_SIZE];

    if (argc < 3) {
        printf("Usage:./smtp_client <server_ip> <port_number>\n");
        return 1;
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server successfully\n");

    while (1) {
        printf("Enter command: ");
        fgets(send_buffer, BUF_SIZE, stdin);
        send(sockfd, send_buffer, strlen(send_buffer), 0);

        memset(recv_buffer, 0, BUF_SIZE);
        n = recv(sockfd, recv_buffer, BUF_SIZE, 0);

        if (n <= 0) {
            printf("Error reading response from server\n");
            exit(1);
        }

        printf("Response from server: %s", recv_buffer);
    }

    close(sockfd);
    return 0;
}