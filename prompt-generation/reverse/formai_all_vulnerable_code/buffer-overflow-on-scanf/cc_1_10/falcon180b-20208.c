//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 110
#define MAX 1024

char username[50];
char password[50];
char server[50];

void main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[MAX];
    char recv_buffer[MAX];

    printf("Enter the POP3 server address: ");
    scanf("%s", server);

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("\n Socket creation failed ");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(server);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Connection Failed ");
        exit(0);
    }

    printf("\n Connected to %s\n", server);

    sprintf(send_buffer, "USER %s\r\n", username);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    recv(sockfd, recv_buffer, MAX, 0);

    printf("\n %s", recv_buffer);

    sprintf(send_buffer, "PASS %s\r\n", password);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    recv(sockfd, recv_buffer, MAX, 0);

    printf("\n %s", recv_buffer);

    close(sockfd);
}