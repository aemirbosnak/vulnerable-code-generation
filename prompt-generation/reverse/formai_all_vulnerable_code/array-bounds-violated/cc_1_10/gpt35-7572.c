//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 512
#define POP_PORT 110
#define POP_SERVER "pop3.server.com"

int main() {
    char buff[MAX_BUFF_SIZE];
    char user[MAX_BUFF_SIZE], pass[MAX_BUFF_SIZE];
    int sockfd, readSize;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Prepare the sockaddr_in structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(POP_SERVER);

    // Connect to POP3 server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to POP3 server\n");
        return 1;
    }

    // Send user command to server
    printf("Username: ");
    fflush(stdout);
    fgets(user, MAX_BUFF_SIZE, stdin);
    user[strcspn(user, "\n")] = '\0';
    sprintf(buff, "USER %s\r\n", user);
    send(sockfd, buff, strlen(buff), 0);

    // Wait for response
    readSize = recv(sockfd, buff, MAX_BUFF_SIZE, 0);
    buff[readSize] = '\0';
    printf("%s", buff);

    // Send pass command to server
    printf("Password: ");
    fflush(stdout);
    fgets(pass, MAX_BUFF_SIZE, stdin);
    pass[strcspn(pass, "\n")] = '\0';
    sprintf(buff, "PASS %s\r\n", pass);
    send(sockfd, buff, strlen(buff), 0);

    // Wait for response
    readSize = recv(sockfd, buff, MAX_BUFF_SIZE, 0);
    buff[readSize] = '\0';
    printf("%s", buff);

    // Send STAT command to server
    sprintf(buff, "STAT\r\n");
    send(sockfd, buff, strlen(buff), 0);

    // Wait for response
    readSize = recv(sockfd, buff, MAX_BUFF_SIZE, 0);
    buff[readSize] = '\0';
    printf("%s", buff);

    // Close socket
    close(sockfd);

    return 0;
}