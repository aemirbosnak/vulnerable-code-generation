#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PACKET_SIZE 1400

void read_packet(char *packet, int length) {
    char buffer[PACKET_SIZE];
    memcpy(buffer, packet + length, sizeof(buffer)); // Out of bounds read vulnerability
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    char packet[PACKET_SIZE];
    while (1) {
        recvfrom(sockfd, packet, sizeof(packet), 0, NULL, NULL);
        read_packet(packet, PACKET_SIZE); // Triggering the out of bounds read vulnerability
    }

    close(sockfd);
    return 0;
}
