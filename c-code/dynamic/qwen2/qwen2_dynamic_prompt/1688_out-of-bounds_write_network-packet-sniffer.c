#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

void process_packet(unsigned char* buffer, int bytes) {
    // Simulate processing by writing to an unbounded array
    unsigned char* data = malloc(BUFSIZE);
    if (!data) {
        perror("Failed to allocate memory");
        return;
    }
    memcpy(data, buffer, bytes); // Potential out-of-bounds write here
    free(data);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        unsigned char buffer[BUFSIZE];
        socklen_t addr_len = sizeof(server_addr);

        // Receive packet
        int bytes_received = recvfrom(sockfd, buffer, BUFSIZE, 0, (struct sockaddr*)&server_addr, &addr_len);
        if (bytes_received == -1) {
            perror("Receive failed");
            continue;
        }

        // Process packet
        process_packet(buffer, bytes_received);
    }

    close(sockfd);
    return 0;
}
