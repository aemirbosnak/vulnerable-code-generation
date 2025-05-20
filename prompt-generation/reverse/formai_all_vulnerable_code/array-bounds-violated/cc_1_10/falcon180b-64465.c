//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 110
#define BUF_SIZE 1024
#define USERNAME "username"
#define PASSWORD "password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUF_SIZE];
    char recv_buffer[BUF_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    strcpy(send_buffer, "USER ");
    strcat(send_buffer, USERNAME);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    strcpy(send_buffer, "PASS ");
    strcat(send_buffer, PASSWORD);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    while (1) {
        n = recv(sockfd, recv_buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        recv_buffer[n] = '\0';
        printf("%s", recv_buffer);
    }

    close(sockfd);
    return 0;
}