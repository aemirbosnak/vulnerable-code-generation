//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "localhost"
#define PORT 110
#define USER "user"
#define PASS "password"

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[1024];
    char *ptr;
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }

    // Set server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serveraddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    // Authenticate
    send(sockfd, "USER ", 5, 0);
    send(sockfd, USER, strlen(USER), 0);
    send(sockfd, "\r\n", 2, 0);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    ptr = strstr(buffer, "+OK");
    if (ptr == NULL) {
        printf("Failed to authenticate\n");
        exit(1);
    }

    // Get mailbox status
    send(sockfd, "STAT\r\n", 6, 0);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Mailbox status: %s\n", buffer);

    // List messages
    send(sockfd, "LIST\r\n", 6, 0);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Messages:\n%s", buffer);

    // Retrieve message
    char message_number[10];
    printf("Enter message number: ");
    scanf("%s", message_number);
    sprintf(buffer, "RETR %s\r\n", message_number);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Message: %s", buffer);

    // Close connection
    close(sockfd);
    return 0;
}