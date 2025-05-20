#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void read_packet(unsigned char *packet, int size) {
    // Simulate reading data from a network packet
    if (size > BUFFER_SIZE) {
        printf("Packet too large to handle\n");
        return;
    }
    memcpy(packet, "This is a test packet", size);
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr_in source_addr;
    socklen_t addr_len = sizeof(source_addr);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&source_addr, &addr_len);
        if (bytes_received == -1) {
            perror("Receive failed");
            continue;
        }

        // Deliberate out-of-bounds read vulnerability
        read_packet(buffer + bytes_received, 100); // Reading beyond the end of the buffer

        printf("Received %d bytes from %s:%d\n", bytes_received, inet_ntoa(source_addr.sin_addr), ntohs(source_addr.sin_port));
    }

    close(sockfd);
    return 0;
}
