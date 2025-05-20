//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void move_vehicle(const char *command) {
    if (strcmp(command, "forward") == 0) {
        printf("Vehicle moving forward.\n");
    } else if (strcmp(command, "backward") == 0) {
        printf("Vehicle moving backward.\n");
    } else if (strcmp(command, "left") == 0) {
        printf("Vehicle turning left.\n");
    } else if (strcmp(command, "right") == 0) {
        printf("Vehicle turning right.\n");
    } else if (strcmp(command, "stop") == 0) {
        printf("Vehicle stopped.\n");
    } else {
        printf("Invalid command!\n");
    }
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n;
        n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, NULL, NULL);
        buffer[n] = '\0';
        
        printf("Received command: %s\n", buffer);
        move_vehicle(buffer);
    }

    close(sockfd);
    return 0;
}