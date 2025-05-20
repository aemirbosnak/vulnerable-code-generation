//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send request to server
    send(client_socket, "GET /speedtest HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n", strlen("GET /speedtest HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n"), 0);

    // Receive response from server
    bytes_received = 0;
    while ((bytes_received < BUFFER_SIZE) && (bytes_received >= 0)) {
        bytes_received += recv(client_socket, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }

    // Close socket
    close(client_socket);

    // Print response
    printf("Server response:\n%s\n", buffer);

    return 0;
}