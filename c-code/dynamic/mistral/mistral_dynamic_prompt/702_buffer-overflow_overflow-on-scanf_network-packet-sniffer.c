#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc != 2) {
        printf("Usage: ./packet_sniffer <port>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        char buffer[BUFFER_SIZE];

        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cli_addr, &clilen);
        if (n < 0) error("ERROR reading data");

        char *packet = malloc(n + 1);
        strncpy(packet, buffer, n);
        packet[n] = '\0';

        printf("Received packet:\n%s\n", packet);

        // Unsafe scanf call that triggers buffer overflow
        char input[10];
        scanf("%s", input);
    }

    return 0;
}
