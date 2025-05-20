//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_LEN 512

int main() {
    // Create a socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    // Set up a connection to a server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    // Send a message to the server
    char msg[MAX_LEN];
    strcpy(msg, "Hello, server!");
    send(sockfd, msg, strlen(msg), 0);

    // Receive a message from the server
    int recv_msg_size;
    recv(sockfd, &recv_msg_size, sizeof(recv_msg_size), 0);
    char recv_msg[recv_msg_size + 1];
    memset(recv_msg, 0, recv_msg_size + 1);
    recv(sockfd, recv_msg, recv_msg_size, 0);
    recv_msg[recv_msg_size] = '\0';

    // Print the received message
    printf("Server replied: %s\n", recv_msg);

    // Close the socket
    close(sockfd);

    return 0;
}