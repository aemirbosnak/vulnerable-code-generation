#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

void read_packet(unsigned char *buffer, int bytes_read) {
    // Simulate reading data from a network packet
    for (int i = 0; i < bytes_read; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
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
    server_addr.sin_port = htons(80);

    // Bind socket to all interfaces
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFSIZE];
    while (1) {
        int bytes_read = recvfrom(sockfd, buffer, BUFSIZE, 0, NULL, NULL);
        if (bytes_read > 0) {
            read_packet(buffer, bytes_read);
        } else {
            perror("Receive failed");
        }
    }

    close(sockfd);
    return 0;
}
