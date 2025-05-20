//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define SERVER_IP     "192.168.1.1"
#define SERVER_PORT     8080
#define BUFFER_SIZE    1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    char *input;
    char *token;
    char *command;
    char *argument;
    int i;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    while (1) {
        // Get input from user
        printf("\n");
        printf("Enter command (e.g., 'lights on', 'thermostat 70'): ");
        input = fgets(buffer, BUFFER_SIZE, stdin);
        if (input == NULL) {
            perror("fgets");
            return EXIT_FAILURE;
        }

        // Parse input
        token = strtok(input, " ");
        command = token;
        token = strtok(NULL, " ");
        argument = token;

        // Send command to server
        if (strcmp(command, "lights") == 0) {
            if (argument == NULL) {
                printf("Usage: lights on/off\n");
                continue;
            }

            if (strcmp(argument, "on") == 0) {
                strcpy(buffer, "lights on");
            } else if (strcmp(argument, "off") == 0) {
                strcpy(buffer, "lights off");
            } else {
                printf("Invalid argument '%s'\n", argument);
                continue;
            }
        } else if (strcmp(command, "thermostat") == 0) {
            if (argument == NULL) {
                printf("Usage: thermostat temperature\n");
                continue;
            }

            sprintf(buffer, "thermostat %s", argument);
        } else {
            printf("Invalid command '%s'\n", command);
            continue;
        }

        // Send command to server
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            return EXIT_FAILURE;
        }

        // Receive response from server
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            return EXIT_FAILURE;
        }

        // Print response
        printf("%s\n", buffer);
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}