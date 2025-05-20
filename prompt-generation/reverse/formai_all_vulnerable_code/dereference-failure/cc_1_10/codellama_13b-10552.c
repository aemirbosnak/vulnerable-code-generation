//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: surprised
/*
 * Unique C Port Scanner Example Program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *host;
    char *port;
    int port_num;

    // Check if the host and port were specified as arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = argv[2];

    // Convert the port number from string to integer
    port_num = atoi(port);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Get the server address
    server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname() failed");
        return 1;
    }

    // Fill in the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Check if the port is open
    if (recv(sock, NULL, 0, MSG_PEEK) == 0) {
        printf("Port %s is open\n", port);
    } else {
        printf("Port %s is closed\n", port);
    }

    // Close the socket
    close(sock);

    return 0;
}