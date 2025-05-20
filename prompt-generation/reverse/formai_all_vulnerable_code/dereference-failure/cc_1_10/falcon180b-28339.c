//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE];
    char *message = "Hello, world!\r\n";
    int message_len = strlen(message);

    // Initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, addrlen) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    // Start sending message
    if (send(sock, message, message_len, 0) == -1) {
        printf("Error sending message: %s\n", strerror(errno));
        return 1;
    }

    // Start receiving message
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving message: %s\n", strerror(errno));
        return 1;
    }

    printf("Received message: %s\n", buffer);

    close(sock);
    return 0;
}