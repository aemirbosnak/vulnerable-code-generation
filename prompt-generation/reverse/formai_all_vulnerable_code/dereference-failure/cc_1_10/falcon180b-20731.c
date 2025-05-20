//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT "25"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char recv_buffer[BUFFER_SIZE];
    char send_buffer[BUFFER_SIZE];
    int n;
    int opt = 1;

    if (argc < 3) {
        printf("Usage:./client <server_ip> <username> <password>\n");
        return 1;
    }

    strcpy(send_buffer, "HELO ");
    strcat(send_buffer, argv[1]);
    strcat(send_buffer, "\r\n");

    strcpy(send_buffer, "AUTH LOGIN\r\n");

    strcpy(send_buffer, argv[2]);
    strcat(send_buffer, "\r\n");

    strcpy(send_buffer, argv[3]);
    strcat(send_buffer, "\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: connection failed\n");
        return 1;
    }

    send(sockfd, send_buffer, strlen(send_buffer), 0);

    while (1) {
        memset(recv_buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }

        printf("%s", recv_buffer);
    }

    close(sockfd);

    return 0;
}