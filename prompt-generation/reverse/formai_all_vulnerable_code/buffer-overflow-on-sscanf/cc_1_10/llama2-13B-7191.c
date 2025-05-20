//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sock, conn_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[256];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept an incoming connection
    conn_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (conn_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Read the request from the client
    read(conn_sock, buffer, 256);
    printf("Received request: %s\n", buffer);

    // Perform the arithmetic operation
    int num1, num2, sum;
    sscanf(buffer, "%d%d", &num1, &num2);
    sum = num1 + num2;

    // Send the result back to the client
    char result[256];
    sprintf(result, "%d", sum);
    send(conn_sock, result, strlen(result), 0);

    // Close the socket
    close(conn_sock);

    return 0;
}