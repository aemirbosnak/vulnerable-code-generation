//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set the socket address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send a message to the server
    char *msg = "Hello, world!";
    int msg_len = strlen(msg);
    if (send(sockfd, msg, msg_len, 0) < 0) {
        perror("send");
        return -1;
    }

    // Receive a message from the server
    char buf[MAX_MSG_SIZE];
    int recv_len = recv(sockfd, buf, MAX_MSG_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        return -1;
    }
    buf[recv_len] = '\0';

    // Print the message from the server
    printf("Received from server: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}