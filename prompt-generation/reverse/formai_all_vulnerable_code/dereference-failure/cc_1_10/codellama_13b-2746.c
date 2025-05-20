//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send a message to the server
    printf("Enter message: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    send(sock, buffer, strlen(buffer), 0);

    // Receive a message from the server
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("Message from server: %s", buffer);

    // Close the socket
    close(sock);

    return 0;
}