//Gemma-7B DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_MSG_LEN 1024

int main() {
    int sockfd, port, len, n, i, msg_len;
    char buf[MAX_MSG_LEN], msg[MAX_MSG_LEN];

    // Open a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(25));
    if (sockfd == -1) {
        perror("Error opening socket");
        exit(1);
    }

    // Connect to a server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("localhost");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message
    printf("Enter your message: ");
    fgets(msg, MAX_MSG_LEN, stdin);
    msg_len = strlen(msg) + 1;
    if (send(sockfd, msg, msg_len, 0) == -1) {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message
    len = recv(sockfd, buf, MAX_MSG_LEN, 0);
    if (len > 0) {
        buf[len] = '\0';
        printf("Received message: %s\n", buf);
    }

    // Close the socket
    close(sockfd);

    return 0;
}