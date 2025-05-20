//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *server;
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;
    char *username, *password;
    char *host, *port;

    // Parse command line arguments
    if (argc!= 6) {
        printf("Usage: %s hostname port username password\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = argv[2];
    username = argv[3];
    password = argv[4];

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve server address
    if (getaddrinfo(host, port, &hints, &server)!= 0) {
        printf("Error resolving server address: %s\n", gai_strerror(errno));
        return 1;
    }

    // Create socket
    sock = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Connect to server
    if (connect(sock, server->ai_addr, server->ai_addrlen) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Send login credentials
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    // Receive server response
    bytes_received = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving server response\n");
        close(sock);
        return 1;
    }

    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}