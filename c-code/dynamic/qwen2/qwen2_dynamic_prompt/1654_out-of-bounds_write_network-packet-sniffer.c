#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

void packet_sniffer() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFSIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive data from socket
        ssize_t bytes_received = recvfrom(sockfd, buffer, BUFSIZE, 0, NULL, NULL);
        if (bytes_received == -1) {
            perror("Receive failed");
            continue;
        }

        // Process received data
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);

        // Out-of-bounds write vulnerability
        buffer[BUFSIZE] = 'X'; // This line intentionally causes an out-of-bounds write
    }

    close(sockfd);
}

int main() {
    packet_sniffer();
    return 0;
}
