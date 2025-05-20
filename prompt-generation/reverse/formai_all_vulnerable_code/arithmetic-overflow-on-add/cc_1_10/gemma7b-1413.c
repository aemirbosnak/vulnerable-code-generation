//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_PACKET_SIZE 1024

int main() {
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char packet[MAX_PACKET_SIZE];
    int packet_size, bytes_received, total_bytes_received = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0) {
        perror("Error accepting client connection");
        exit(1);
    }

    // Receive packets from the client
    while (1) {
        packet_size = recv(client_sockfd, packet, MAX_PACKET_SIZE, 0);
        if (packet_size > 0) {
            total_bytes_received += packet_size;
            printf("Received packet of size %d bytes\n", packet_size);
        } else if (packet_size == 0) {
            printf("Client disconnected\n");
            break;
        } else {
            perror("Error receiving packet");
            break;
        }
    }

    // Close the socket
    close(client_sockfd);
    close(sockfd);

    // Print the total number of bytes received
    printf("Total bytes received: %d\n", total_bytes_received);

    return 0;
}