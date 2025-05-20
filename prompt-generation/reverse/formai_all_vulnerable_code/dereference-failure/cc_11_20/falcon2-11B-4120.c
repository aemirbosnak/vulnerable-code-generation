//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, newsockfd, pid, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[256];

    if ((portno = 8888) < 0) {
        fprintf(stderr, "ERROR: Invalid port number\n");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Invalid host name\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: Failed to create socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(long *)server->h_addr;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: Failed to connect to server\n");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, 255);
        if (n <= 0) {
            fprintf(stderr, "ERROR: Failed to read from socket\n");
            exit(1);
        }

        if (strncmp(buffer, "takeoff", 8) == 0) {
            // Code to take off the drone
            printf("Taking off the drone...\n");
        }
        else if (strncmp(buffer, "land", 5) == 0) {
            // Code to land the drone
            printf("Landing the drone...\n");
        }
        else if (strncmp(buffer, "forward", 7) == 0) {
            // Code to move the drone forward
            printf("Moving the drone forward...\n");
        }
        else if (strncmp(buffer, "backward", 8) == 0) {
            // Code to move the drone backward
            printf("Moving the drone backward...\n");
        }
        else if (strncmp(buffer, "left", 4) == 0) {
            // Code to move the drone to the left
            printf("Moving the drone to the left...\n");
        }
        else if (strncmp(buffer, "right", 5) == 0) {
            // Code to move the drone to the right
            printf("Moving the drone to the right...\n");
        }
        else if (strncmp(buffer, "up", 2) == 0) {
            // Code to move the drone up
            printf("Moving the drone up...\n");
        }
        else if (strncmp(buffer, "down", 4) == 0) {
            // Code to move the drone down
            printf("Moving the drone down...\n");
        }
        else {
            printf("Unknown command\n");
        }
    }

    return 0;
}