//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {

    int sockfd;
    struct sockaddr_in server_addr;
    char ping_message[] = "Ping!";
    char received_message[1024];
    int bytes_sent = 0;
    int bytes_received = 0;
    float round_trip_time = 0.0f;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Send the ping message
    bytes_sent = sendto(sockfd, ping_message, sizeof(ping_message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bytes_sent < 0) {
        perror("Error sending ping message");
        exit(1);
    }

    // Receive the received message
    bytes_received = recvfrom(sockfd, received_message, 1024, 0, (struct sockaddr *)&server_addr, NULL);
    if (bytes_received < 0) {
        perror("Error receiving ping message");
        exit(1);
    }

    // Calculate the round-trip time
    round_trip_time = (float)bytes_received / (float)bytes_sent;

    // Print the results
    printf("Sent: %s\n", ping_message);
    printf("Received: %s\n", received_message);
    printf("Round-trip time: %.2f milliseconds\n", round_trip_time);

    // Close the socket
    close(sockfd);

    return 0;
}