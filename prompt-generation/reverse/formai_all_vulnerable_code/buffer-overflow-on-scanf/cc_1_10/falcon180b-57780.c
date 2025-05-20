//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096
#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[MAX_COMMAND_LENGTH], recv_buf[MAX_RESPONSE_LENGTH];
    char username[64], password[64];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(IMAP_PORT);

    if (inet_pton(AF_INET, "localhost", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        close(sockfd);
        return 1;
    }

    snprintf(send_buf, MAX_COMMAND_LENGTH, "LOGIN %s %s\r\n", username, password);
    send(sockfd, send_buf, strlen(send_buf), 0);

    while (1) {
        memset(recv_buf, 0, MAX_RESPONSE_LENGTH);
        n = recv(sockfd, recv_buf, MAX_RESPONSE_LENGTH, 0);
        if (n <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("%s", recv_buf);
    }

    close(sockfd);
    return 0;
}