//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: grateful
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    const char *server_ip = "127.0.0.1";

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("socket: unable to create socket");
    }
    printf("Socket created successfully\n");

    // Configure address settings
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("connect: unable to connect to server");
    }
    printf("Connected to server\n");

    // Send a grateful message to the server
    const char *message = "Hello, I am grateful for this opportunity to connect and communicate.";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        die("send: unable to send message");
    }
    printf("Message sent to server\n");

    // Receive response from server
    char buffer[BUFFER_SIZE];
    ssize_t n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        die("recv: unable to receive data");
    }
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // Close the socket and exit
    close(sockfd);
    printf("Connection closed\n");
    return 0;
}