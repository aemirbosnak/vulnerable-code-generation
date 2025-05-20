//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5678

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Create a buffer for the light command
    char buffer[100];

    // Main loop
    while (1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read the light command from the user
        printf("Enter a light command (on/off/toggle): ");
        scanf("%s", buffer);

        // Send the light command to the server
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
            perror("sendto");
            return EXIT_FAILURE;
        }

        // Receive the response from the server
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL) == -1) {
            perror("recvfrom");
            return EXIT_FAILURE;
        }

        // Print the response from the server
        printf("Response from server: %s\n", buffer);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}