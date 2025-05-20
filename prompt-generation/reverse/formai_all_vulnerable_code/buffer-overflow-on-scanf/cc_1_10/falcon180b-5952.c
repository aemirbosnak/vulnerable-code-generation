//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    char username[20];
    char password[20];
    char command[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(send_buffer, "USER %s\r\n", username);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    if (recv(sockfd, recv_buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s", recv_buffer);

    sprintf(send_buffer, "PASS %s\r\n", password);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    if (recv(sockfd, recv_buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s", recv_buffer);

    while (1) {
        printf("Enter command (e.g. ls, get file.txt): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        sprintf(send_buffer, "%s\r\n", command);
        send(sockfd, send_buffer, strlen(send_buffer), 0);

        if (recv(sockfd, recv_buffer, BUFFER_SIZE, 0) < 0) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Response: %s", recv_buffer);
    }

    close(sockfd);

    return 0;
}