#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFSIZE];
    int n;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        n = recvfrom(sockfd, (char *)buffer, BUFSIZE, MSG_WAITALL, (struct sockaddr *)NULL, NULL);
        buffer[n] = '\0';
        printf("Received command: %s\n", buffer);

        if (strcmp(buffer, "takeoff") == 0) {
            system("echo 'takeoff' > /dev/ttyUSB0");
        } else if (strcmp(buffer, "land") == 0) {
            system("echo 'land' > /dev/ttyUSB0");
        } else if (strncmp(buffer, "move ", 5) == 0) {
            char direction[6];
            strncpy(direction, buffer + 5, 5);
            direction[5] = '\0';
            system(printf("echo 'move %s' > /dev/ttyUSB0", direction));
        } else {
            printf("Unknown command\n");
        }
    }

    close(sockfd);
    return 0;
}
