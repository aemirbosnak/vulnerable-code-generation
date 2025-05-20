//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_PORT_NUMBERS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port_start, port_end;
    char *ip_address;
    struct addrinfo hints, *result, *rp;
    int sfd, new_socket;
    char buffer[BUFFER_SIZE];
    int val;

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Start> <Port End>\n", argv[0]);
        exit(1);
    }

    // Convert IP address from string to binary format
    ip_address = argv[1];
    struct in_addr addr;
    inet_pton(AF_INET, ip_address, &addr);

    // Initialize socket
    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set up address structure for connect()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip_address, NULL, &hints, &result)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    // Connect to the first port
    if (connect(sfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    // Loop through all ports
    for (port_start = atoi(argv[2]); port_start <= atoi(argv[3]); port_start++) {
        // Create a new socket for each port
        if ((new_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket failed");
            exit(1);
        }

        // Set up address structure for connect()
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        if (getaddrinfo(ip_address, NULL, &hints, &result)!= 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
            exit(1);
        }

        // Connect to the port
        if (connect(new_socket, result->ai_addr, result->ai_addrlen) == -1) {
            if (errno!= ECONNREFUSED) {
                perror("connect");
                exit(1);
            } else {
                // Port is closed, continue to next port
                close(new_socket);
                continue;
            }
        }

        // Send data to the port
        send(new_socket, "HELLO\r\n", 7, 0);

        // Receive data from the port
        if ((val = recv(new_socket, buffer, BUFFER_SIZE, 0)) == -1) {
            perror("recv");
            exit(1);
        }

        // Print response
        buffer[val] = '\0';
        printf("Port %d: %s\n", port_start, buffer);

        // Close the socket
        close(new_socket);
    }

    // Close the main socket
    close(sfd);

    return 0;
}