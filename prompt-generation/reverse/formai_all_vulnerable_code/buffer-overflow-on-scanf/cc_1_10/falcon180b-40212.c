//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER "localhost"
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    char username[30], password[30];
    char response[30];
    int status;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sprintf(send_buf, "USER %s\r\n", username);
    send(sockfd, send_buf, strlen(send_buf), 0);

    recv(sockfd, recv_buf, BUF_SIZE, 0);
    printf("Server response: %s\n", recv_buf);

    sprintf(send_buf, "PASS %s\r\n", password);
    send(sockfd, send_buf, strlen(send_buf), 0);

    recv(sockfd, recv_buf, BUF_SIZE, 0);
    printf("Server response: %s\n", recv_buf);

    // Retrieve messages from server
    send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0);

    while ((n = recv(sockfd, recv_buf, BUF_SIZE, 0)) > 0) {
        printf("Server response: %s\n", recv_buf);
    }

    close(sockfd);
    return 0;
}