#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

void read_packet(unsigned char *packet, int len) {
    printf("Packet length: %d\n", len);
    // Out-of-bounds read vulnerability
    printf("%s\n", packet + len); // Potential buffer overflow here
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    unsigned char buffer[BUFSIZE];

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    while (1) {
        int bytes_received = recvfrom(sockfd, buffer, BUFSIZE, 0, NULL, NULL);
        if (bytes_received > 0) {
            read_packet(buffer, bytes_received);
        }
    }

    close(sockfd);
    return 0;
}
