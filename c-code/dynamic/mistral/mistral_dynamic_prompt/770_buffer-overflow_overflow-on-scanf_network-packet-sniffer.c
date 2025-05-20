#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, len, i, j;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in addr;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    while (1) {
        len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (len > 0) {
            printf("Received packet: %s\n", buffer);

            // Buffer overflow vulnerability here (intentional):
            char ip_header[20];
            scanf("%19s", ip_header);

            // ... (the rest of the code to parse the packet, if you wanted to)
        }
    }

    return 0;
}
