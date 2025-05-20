//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    char user_name[BUFFER_SIZE], pass_word[BUFFER_SIZE];

    printf("Enter POP3 Server IP: ");
    scanf("%s", &user_name);

    printf("Enter Username: ");
    scanf("%s", &user_name);

    printf("Enter Password: ");
    scanf("%s", &pass_word);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    inet_pton(AF_INET, user_name, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    sprintf(send_buffer, "USER %s\r\n", user_name);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = '\0';
    printf("Received from server: %s", recv_buffer);

    sprintf(send_buffer, "PASS %s\r\n", pass_word);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = '\0';
    printf("Received from server: %s", recv_buffer);

    close(sockfd);
}