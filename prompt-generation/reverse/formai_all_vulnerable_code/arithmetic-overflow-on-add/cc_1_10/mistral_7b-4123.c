//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Define constants
#define PORT 5000
#define BUFFER_SIZE 1024
#define NUM_ECHOES 5

typedef struct {
    char sender[INET_ADDRSTRLEN];
    char message[BUFFER_SIZE];
} packet_t;

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, recv_len;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    int i;
    packet_t received_packet;

    // Initialization
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming messages
    printf("Server is listening on port %d\n", PORT);

    while (1) {
        cli_len = sizeof(cli_addr);

        // Receive a packet from a client
        recv_len = recvfrom(sockfd, (char *)&received_packet, sizeof(packet_t), 0, (struct sockaddr *)&cli_addr, &cli_len);
        if (recv_len < 0) {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        // Print the received packet details
        printf("Received packet from %s:\nMessage: %s\n", inet_ntoa(cli_addr.sin_addr), received_packet.message);

        // Send an echo message back to the client
        packet_t echo_packet;
        strcpy(echo_packet.message, received_packet.message);
        sendto(sockfd, (char *)&echo_packet, sizeof(packet_t), 0, (struct sockaddr *)&cli_addr, cli_len);

        // Increment the counter and check for the maximum number of echoes
        i++;
        if (i == NUM_ECHOES) {
            printf("Number of echoes reached. Exiting...\n");
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}