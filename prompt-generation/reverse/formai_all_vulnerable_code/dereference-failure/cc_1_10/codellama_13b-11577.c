//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to establish connection with the server
int establish_connection(const char *host, const char *port) {
    int sock_fd;
    struct addrinfo hints, *servinfo, *p;

    // Initialize the hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get the address information of the server
    if (getaddrinfo(host, port, &hints, &servinfo) != 0) {
        fprintf(stderr, "getaddrinfo() failed\n");
        return -1;
    }

    // Loop through all the address structures until we find one that works
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }
        if (connect(sock_fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock_fd);
            continue;
        }
        break;
    }

    // Free the address information structure
    freeaddrinfo(servinfo);

    // Return the socket file descriptor
    return sock_fd;
}

// Function to send data to the server
int send_data(int sock_fd, const char *data) {
    return send(sock_fd, data, strlen(data), 0);
}

// Function to receive data from the server
int receive_data(int sock_fd, char *buffer, int buffer_size) {
    return recv(sock_fd, buffer, buffer_size, 0);
}

int main() {
    // Establish a connection with the server
    int sock_fd = establish_connection("localhost", "8080");
    if (sock_fd == -1) {
        fprintf(stderr, "Could not establish connection with the server\n");
        return -1;
    }

    // Send data to the server
    char *data = "Hello, server!";
    send_data(sock_fd, data);

    // Receive data from the server
    char buffer[1024];
    int received = receive_data(sock_fd, buffer, 1024);
    if (received == -1) {
        fprintf(stderr, "Could not receive data from the server\n");
        return -1;
    }
    printf("Received %d bytes from the server: %s\n", received, buffer);

    // Close the connection
    close(sock_fd);

    return 0;
}