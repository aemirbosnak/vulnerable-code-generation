//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main() {
    int sock, port, i, j, k;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[256];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1234);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // Statistical analysis of incoming connections
    int num_connections = 0;
    int num_unique_ports = 0;
    int num_connections_per_port[PORT_RANGE];
    int max_connections_per_port = 0;
    int min_connections_per_port = 0;
    int avg_connections_per_port = 0;

    while (1) {
        // Accept an incoming connection
        if ((sock = accept(sock, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Increment the number of connections
        num_connections++;

        // Check if the port is already in the statistics
        for (i = 0; i < PORT_RANGE; i++) {
            if (num_connections_per_port[i] == 0) {
                num_unique_ports++;
                num_connections_per_port[i] = 1;
                break;
            }
        }

        // Update the statistics for the current port
        for (i = 0; i < PORT_RANGE; i++) {
            if (client.sin_port == htons(i)) {
                num_connections_per_port[i]++;
                if (num_connections_per_port[i] > max_connections_per_port) {
                    max_connections_per_port = num_connections_per_port[i];
                }
                if (num_connections_per_port[i] < min_connections_per_port) {
                    min_connections_per_port = num_connections_per_port[i];
                }
                avg_connections_per_port += num_connections_per_port[i];
                break;
            }
        }

        // Print the statistics
        printf("Connections: %d\n", num_connections);
        printf("Unique ports: %d\n", num_unique_ports);
        for (i = 0; i < PORT_RANGE; i++) {
            printf("Port %d: %d\n", i, num_connections_per_port[i]);
        }
        printf("Max connections per port: %d\n", max_connections_per_port);
        printf("Min connections per port: %d\n", min_connections_per_port);
        avg_connections_per_port /= num_connections;
        printf("Average connections per port: %d\n", avg_connections_per_port);

        // Close the socket
        close(sock);
    }

    return 0;
}