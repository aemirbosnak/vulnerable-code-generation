//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char receive_buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send message to server
    strcpy(send_buffer, "Hello, server!");
    bytes_received = send(server_socket, send_buffer, strlen(send_buffer), 0);
    if (bytes_received == -1) {
        printf("Error sending message: %s\n", strerror(errno));
        exit(1);
    }

    // Receive message from server
    bytes_received = recv(server_socket, receive_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving message: %s\n", strerror(errno));
        exit(1);
    }
    receive_buffer[bytes_received] = '\0';
    printf("Message from server: %s\n", receive_buffer);

    // Close socket
    close(server_socket);
    return 0;
}