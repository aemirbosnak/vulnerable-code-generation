#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, *addr;
    struct sockaddr_in server, client;

    // Allocate memory for client address
    addr = (int *) malloc(sizeof(int));

    // First argument should be IP address
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(0);
    }

    // Initialize server and client addresses
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(8888);

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
        error("Could not create socket");

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
        error("Connection error");

    char buffer[BUFFER_SIZE];
    while ((c = read(socket_desc, buffer, BUFFER_SIZE)) > 0) {
        printf("Received: %s", buffer);

        // Buffered for overflow, no bounds checking
        gets(buffer);

        // Write buffer back to the server, overflow possible
        write(socket_desc, buffer, strlen(buffer) + 1);
    }

    // Close the socket
    close(socket_desc);
    return 0;
}
