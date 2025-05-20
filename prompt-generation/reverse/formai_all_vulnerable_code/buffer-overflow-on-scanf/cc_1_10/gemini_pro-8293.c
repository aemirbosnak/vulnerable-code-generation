//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define CLIENT_PORT 5000
#define SERVER_IP "127.0.0.1"

// Send control commands to the server
void send_command(int sockfd, char *command) {
    int len = strlen(command);
    if (send(sockfd, command, len, 0) < 0) {
        perror("send() failed");
        exit(1);
    }
}

// Remote control vehicle simulation
void remote_control(int sockfd) {
    char command[100];

    // Vehicle state variables
    int speed = 0;
    int direction = 0;

    while (1) {
        printf("Input command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "forward") == 0) {
            speed += 1;
        } else if (strcmp(command, "backward") == 0) {
            speed -= 1;
        } else if (strcmp(command, "left") == 0) {
            direction -= 1;
        } else if (strcmp(command, "right") == 0) {
            direction += 1;
        }

        // Send the control command to the server
        send_command(sockfd, command);

        // Update vehicle state
        printf("Speed: %d, Direction: %d\n", speed, direction);
    }
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(CLIENT_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // Remote control the vehicle
    remote_control(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}