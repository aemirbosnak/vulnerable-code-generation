//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMART_HOME_IP "192.168.1.100"
#define SMART_HOME_PORT 12345

typedef struct {
    char command;
    char id[32];
} LightCommand;

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // Initialize UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMART_HOME_PORT);
    inet_pton(AF_INET, SMART_HOME_IP, &serv_addr.sin_addr);

    // Loop for controlling lights
    while (1) {
        char lightId[32];
        printf("Enter light ID: ");
        scanf("%s", lightId);
        LightCommand command = {'L', lightId};

        // Send command to Smart Home server
        if (sendto(sockfd, &command, sizeof(command), 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("Failed to send command");
            continue;
        }

        // Wait for response
        memset(buffer, 0, sizeof(buffer));
        int len = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (len < 0) {
            perror("Failed to receive response");
            continue;
        }

        // Parse response and print status
        LightCommand response;
        memcpy(&response, buffer, sizeof(response));
        if (strcmp(response.id, lightId) == 0) {
            printf("Light %s is %s\n", lightId, response.command == 'T' ? "on" : "off");
        }
    }

    // Close socket
    close(sockfd);
    return 0;
}