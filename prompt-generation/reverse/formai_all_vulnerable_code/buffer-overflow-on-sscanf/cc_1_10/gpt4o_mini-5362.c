//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

unsigned short checksum(const char *buf, int len) {
    unsigned short sum = 0;
    for (int i = 0; i < len; i++) {
        sum += buf[i];
    }
    return sum;
}

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Filling server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    printf("UDP Server is up and running on port %d\n", PORT);

    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *) &client_addr, &addr_len);
        buffer[n] = '\0';

        unsigned short received_checksum;
        sscanf(buffer + n - 5, "%hu", &received_checksum);
        buffer[n - 5] = '\0'; // Remove checksum from message

        unsigned short calculated_checksum = checksum(buffer, n - 5);
        printf("Received message: %s with checksum: %hu\n", buffer, received_checksum);

        if (calculated_checksum == received_checksum) {
            printf("Checksum valid. Message integrity is intact.\n");
        } else {
            printf("Checksum mismatch! Message integrity compromised.\n");
        }

        const char *response = "Message received.";
        sendto(sockfd, response, strlen(response), MSG_CONFIRM, (const struct sockaddr *) &client_addr, addr_len);
    }

    close(sockfd);
    return 0;
}