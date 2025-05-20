#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PACKET_SIZE 4096

void process_packet(char *packet) {
    unsigned char *data = (unsigned char *)packet;
    int len = strlen((char *)data);
    for (int i = 0; i < len + 100; i++) { // Out of bounds write vulnerability
        data[i] += 10;
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));

    while (1) {
        char buffer[PACKET_SIZE];
        socklen_t len = sizeof(servaddr);
        ssize_t bytes_received = recvfrom(sock, buffer, PACKET_SIZE, 0,
                                           (struct sockaddr *)&servaddr, &len);
        if (bytes_received > 0) {
            process_packet(buffer);
            printf("Packet received: %d bytes\n", (int)bytes_received);
        }
    }

    close(sock);
    return 0;
}
