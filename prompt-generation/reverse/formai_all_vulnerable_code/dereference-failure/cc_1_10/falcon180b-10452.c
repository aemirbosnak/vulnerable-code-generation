//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server;
    int port = 80;
    int scanned_ports = 0;
    int open_ports = 0;
    char buffer[BUFFER_SIZE];

    printf("C Port Scanner by [Your Name Here]\n\n");

    if (argc < 3) {
        printf("Usage: %s [IP Address] [Port Range]\n", argv[0]);
        return 1;
    }

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        printf("Invalid IP Address\n");
        return 1;
    }

    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    while (port <= MAX_PORTS) {
        if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
            open_ports++;
        } else {
            printf("Port %d is closed\n", port);
        }
        scanned_ports++;
        port++;
    }

    close(sockfd);

    printf("\nScan complete!\n");
    printf("Scanned %d ports\n", scanned_ports);
    printf("Found %d open ports\n", open_ports);

    return 0;
}