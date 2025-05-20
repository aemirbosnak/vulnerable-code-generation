//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERVER_PORT 12345
#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        error_handling("socket failed");
        exit(1);
    }

    printf("Socket created.\n");

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
        exit(1);
    }

    printf("Connected to server.\n");

    // Send data to server
    while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Receive data from server
    while (recv(client_socket, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    // Close socket
    close(client_socket);

    printf("Connection closed.\n");

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    if (errno!= 0) {
        fprintf(stderr, "Error code: %d\n", errno);
    }
    exit(1);
}