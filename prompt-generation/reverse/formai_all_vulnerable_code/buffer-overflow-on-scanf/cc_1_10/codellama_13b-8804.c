//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
// POP3 Client Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_MSG_LEN 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvbuf[MAX_MSG_LEN];
    char *username, *password;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Initialize address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Get username and password from user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Send username and password
    if (send(sockfd, username, strlen(username), 0) < 0) {
        perror("send");
        exit(1);
    }
    if (send(sockfd, password, strlen(password), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive server response
    if ((n = recv(sockfd, recvbuf, MAX_MSG_LEN, 0)) < 0) {
        perror("recv");
        exit(1);
    }
    recvbuf[n] = '\0';
    printf("Server response: %s\n", recvbuf);

    // Close socket
    close(sockfd);

    return 0;
}