//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define STMP_PORT 25
#define USER "your_username"
#define PASSWORD "your_password"
#define SERVER "pop3.example.com"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char recv_buffer[BUFFER_SIZE];
    char send_buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    sprintf(send_buffer, "USER %s\r\n", USER);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = '\0';
    printf("Received: %s", recv_buffer);

    sprintf(send_buffer, "PASS %s\r\n", PASSWORD);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = '\0';
    printf("Received: %s", recv_buffer);

    sprintf(send_buffer, "LIST\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = '\0';
    printf("Received: %s", recv_buffer);

    close(sockfd);

    return 0;
}