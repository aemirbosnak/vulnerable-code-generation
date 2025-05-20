#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void process_packet(unsigned char* buffer, int length) {
    // Simulate processing a packet
    printf("Packet received: %d bytes\n", length);
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

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    while (1) {
        int len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (len > 0) {
            process_packet(buffer, len);
        }
    }

    close(sockfd);
    return 0;
}
