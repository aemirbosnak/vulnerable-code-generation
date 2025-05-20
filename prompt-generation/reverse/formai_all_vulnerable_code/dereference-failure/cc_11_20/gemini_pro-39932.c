//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8888
#define BUF_SIZE 1024

int main()
{
    int sockfd, n;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from the client
    char buf[BUF_SIZE];
    while (1)
    {
        n = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&servaddr, (socklen_t *)sizeof(servaddr));
        if (n < 0)
        {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        // Parse the data received from the client
        char *token = strtok(buf, " ");
        if (strcmp(token, "takeoff") == 0)
        {
            printf("Taking off...\n");
        }
        else if (strcmp(token, "land") == 0)
        {
            printf("Landing...\n");
        }
        else if (strcmp(token, "up") == 0)
        {
            printf("Moving up...\n");
        }
        else if (strcmp(token, "down") == 0)
        {
            printf("Moving down...\n");
        }
        else if (strcmp(token, "left") == 0)
        {
            printf("Moving left...\n");
        }
        else if (strcmp(token, "right") == 0)
        {
            printf("Moving right...\n");
        }
        else if (strcmp(token, "forward") == 0)
        {
            printf("Moving forward...\n");
        }
        else if (strcmp(token, "backward") == 0)
        {
            printf("Moving backward...\n");
        }
        else if (strcmp(token, "rotate_left") == 0)
        {
            printf("Rotating left...\n");
        }
        else if (strcmp(token, "rotate_right") == 0)
        {
            printf("Rotating right...\n");
        }
        else if (strcmp(token, "flip") == 0)
        {
            printf("Flipping...\n");
        }
        else if (strcmp(token, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}