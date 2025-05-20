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
    for (int i = 0; i < size; i++) {
        packet[i] = rand() % 256;
    }
}

void process_packet(unsigned char *packet, int size) {
    unsigned char *data = packet + 20; // Assume Ethernet header is 14 bytes and IP header is 6 bytes
    int data_size = size - 30;

    if (data_size > 0) {
        printf("Data: ");
        for (int i = 0; i < data_size; i++) {
            printf("%02x ", data[i]);
        }
        printf("\n");
    } else {
        printf("No data in packet.\n");
    }

    // Out-of-bounds read vulnerability
    printf("Out-of-bounds read: %d\n", data[data_size]); // This line intentionally causes an out-of-bounds read
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr_in source_addr;
    socklen_t addr_len = sizeof(source_addr);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    while (1) {
        int packet_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&source_addr, &addr_len);
        if (packet_size == -1) {
            perror("Packet reception failed");
            close(sockfd);
            return EXIT_FAILURE;
        }

        read_packet(buffer, packet_size);
        process_packet(buffer, packet_size);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}
