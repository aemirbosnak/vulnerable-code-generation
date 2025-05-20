#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 4096

void process_packet(unsigned char *packet, int length) {
    unsigned char *ptr = packet;
    while (length > 0) {
        memset(ptr + 100, 'A', length); // Out-of-bounds write
        ptr += 100;
        length -= 100;
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    unsigned char buffer[BUFSIZE];

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    while (1) {
        int n = recvfrom(sockfd, buffer, BUFSIZE, 0, NULL, NULL);
        if (n < 0) {
            perror("Recvfrom failed");
            continue;
        }
        process_packet(buffer, n);
    }

    close(sockfd);
    return 0;
}
