//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to print error messages
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to create a socket
int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error creating socket");
    }
    return sock;
}

// Function to connect to a remote host
int connect_to_host(int sock, char *host, int port) {
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, host, &address.sin_addr);

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("Error connecting to host");
    }
    return sock;
}

// Function to send a ping request
int send_ping_request(int sock) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, "PING");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        error("Error sending ping request");
    }
    return sock;
}

// Function to receive a ping response
int receive_ping_response(int sock) {
    char buffer[BUFFER_SIZE];
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error receiving ping response");
    }
    return sock;
}

// Function to close a socket
void close_socket(int sock) {
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sock = create_socket();
    sock = connect_to_host(sock, host, port);
    sock = send_ping_request(sock);
    sock = receive_ping_response(sock);

    close_socket(sock);

    return 0;
}