//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

struct port_info {
    int port;
    char name[20];
};

void scan_ports(int start, int end) {
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Loop through the port range
    for (int i = start; i <= end; i++) {
        // Create a client socket
        client_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (client_sock < 0) {
            perror("Client socket creation failed");
            continue;
        }

        // Set up the client address
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(i);
        inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);

        // Connect to the server
        if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Client connection failed");
            close(client_sock);
            continue;
        }

        // Send a message to the server
        send(client_sock, "Hello, port #", 13, 0);

        // Receive a message from the server
        recv(client_sock, buffer, 256, 0);

        // Print the received message
        printf("%s\n", buffer);

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(sock);
}

int main() {
    int i, start, end;

    // Ask the user for the start and end ports
    printf("Enter start port (1-65535): ");
    scanf("%d", &start);
    printf("Enter end port (1-65535): ");
    scanf("%d", &end);

    // Check for invalid input
    if (start > end) {
        printf("Start port cannot be greater than end port\n");
        return 1;
    }

    // Scan the ports
    scan_ports(start, end);

    return 0;
}