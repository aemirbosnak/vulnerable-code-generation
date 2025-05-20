//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110
#define USERNAME "username"
#define PASSWORD "password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    sprintf(send_buffer, "USER %s\r\n", USERNAME);
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Error: Failed to send username\n");
        exit(1);
    }

    if ((n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0)) < 0) {
        printf("Error: Failed to receive server response\n");
        exit(1);
    }
    recv_buffer[n] = 0;
    printf("Server response: %s\n", recv_buffer);

    sprintf(send_buffer, "PASS %s\r\n", PASSWORD);
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Error: Failed to send password\n");
        exit(1);
    }

    if ((n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0)) < 0) {
        printf("Error: Failed to receive server response\n");
        exit(1);
    }
    recv_buffer[n] = 0;
    printf("Server response: %s\n", recv_buffer);

    close(sockfd);
    return 0;
}