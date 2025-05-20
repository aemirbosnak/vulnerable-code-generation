//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: curious
/*
 * A curious TCP/IP programming example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check if the user has provided a port number
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Convert the port number to an integer
    int port = atoi(argv[1]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen on the socket
    if (listen(sock, 1) < 0) {
        perror("listen");
        return 1;
    }

    // Accept a connection
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Read data from the client
    char buffer[1024];
    int bytes_read = read(client_sock, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        perror("read");
        return 1;
    }

    // Print the received data
    printf("Received data: %s\n", buffer);

    // Send a response to the client
    char *response = "Hello, world!";
    int bytes_sent = write(client_sock, response, strlen(response));
    if (bytes_sent < 0) {
        perror("write");
        return 1;
    }

    // Close the socket
    close(client_sock);

    return 0;
}