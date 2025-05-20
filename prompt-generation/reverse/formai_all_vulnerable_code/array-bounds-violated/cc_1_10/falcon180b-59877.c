//Falcon-180B DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int n;
    int port = 8080;
    char *ip = "127.0.0.1";

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    // Set up server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    // Send data to server
    strcpy(send_buffer, "Hello, world!");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        error("Error sending data to server");
    }

    // Receive data from server
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        error("Error receiving data from server");
    }
    recv_buffer[n] = '\0';
    printf("Received data: %s\n", recv_buffer);

    // Close socket
    close(sockfd);

    return 0;
}