//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define POP3_PORT 110
#define USERNAME "username"
#define PASSWORD "password"

void die(const char* msg);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char hostname[64];
    char buffer[MAX_LINE_LENGTH];
    char* token;
    int port;
    int status;

    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter POP3 server port (default %d): ", POP3_PORT);
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        die("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        die("connect failed");
    }

    printf("Connected to POP3 server.\n");

    send(sockfd, "USER ", strlen("USER "), 0);
    send(sockfd, USERNAME, strlen(USERNAME), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    status = recv(sockfd, buffer, MAX_LINE_LENGTH, 0);

    if (status <= 0) {
        die("recv failed");
    }

    printf("Received: %s", buffer);

    send(sockfd, "PASS ", strlen("PASS "), 0);
    send(sockfd, PASSWORD, strlen(PASSWORD), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    status = recv(sockfd, buffer, MAX_LINE_LENGTH, 0);

    if (status <= 0) {
        die("recv failed");
    }

    printf("Received: %s", buffer);

    send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0);

    status = recv(sockfd, buffer, MAX_LINE_LENGTH, 0);

    if (status <= 0) {
        die("recv failed");
    }

    printf("Received: %s", buffer);

    close(sockfd);

    return 0;
}

void die(const char* msg) {
    perror(msg);
    exit(1);
}