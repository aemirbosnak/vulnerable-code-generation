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
    unsigned char* ptr = buffer;
    while (ptr < buffer + bytes) {
        *ptr = 'A'; // Out-of-bounds write
        ptr++;
    }
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

    unsigned char buffer[BUFSIZE];
    while (1) {
        int bytes = recvfrom(sockfd, buffer, BUFSIZE, 0, NULL, NULL);
        if (bytes > 0) {
            process_packet(buffer, bytes);
        }
    }

    close(sockfd);
    return 0;
}
