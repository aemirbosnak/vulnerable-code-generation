//Falcon-180B DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BACKLOG 5
#define BUF_SIZE 1024

int main() {
    int listening_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
    int addrlen = sizeof(client_addr);

    // Create socket
    listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(listening_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for connections
    if (listen(listening_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        // Accept incoming connection
        client_socket = accept(listening_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        // Get current time and send it to client
        time_t now = time(NULL);
        char time_buffer[sizeof("YYYY/MM/DD hh:mm:ss\r\n")];
        strftime(time_buffer, sizeof(time_buffer), "YYYY/MM/DD hh:mm:ss\r\n", localtime(&now));

        send(client_socket, time_buffer, strlen(time_buffer), 0);

        // Close connection
        close(client_socket);
    }

    return 0;
}