//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 256

void scanNetwork(char *address);

int main(int argc, char *argv[]) {
    char *address;

    if (argc > 1) {
        address = argv[1];
    } else {
        printf("Please enter the IP address of the network: ");
        scanf("%s", address);
    }

    scanNetwork(address);

    return 0;
}

void scanNetwork(char *address) {
    struct sockaddr_in server;
    int sockfd, count = 0;
    char message[BUFFER_SIZE];

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, address, &server.sin_addr) < 1) {
        perror("Invalid IP address.");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    while (1) {
        sprintf(message, "ping %d", count++);
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr *) &server, sizeof(server));
        sleep(1);
    }

    close(sockfd);
}