//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110
#define BUF_SIZE 1024

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];
    char username[] = "your_username";
    char password[] = "your_password";

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("your_server_ip");
    servaddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Login to server
    sprintf(buf, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    if (strcmp(buf, "OK")!= 0) {
        printf("Login failed.\n");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    if (strcmp(buf, "OK")!= 0) {
        printf("Password incorrect.\n");
        exit(EXIT_FAILURE);
    }

    printf("Login successful.\n");

    // Get the list of messages
    sprintf(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    char *line = strtok(buf, "\r\n");
    char *num = strtok(NULL, "\r\n");
    char *size = strtok(NULL, "\r\n");
    char *date = strtok(NULL, "\r\n");
    char *subject = strtok(NULL, "\r\n");

    while (line) {
        printf("Message %s (%d bytes) %s\n", line, atoi(num), date);
        line = strtok(NULL, "\r\n");
    }

    close(sockfd);

    return 0;
}