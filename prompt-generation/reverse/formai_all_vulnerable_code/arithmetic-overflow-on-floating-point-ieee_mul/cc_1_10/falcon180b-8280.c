//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <math.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MOTOR_POWER 255

int main(int argc, char **argv) {
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    double angle, distance;
    int x, y, speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        clientlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clientlen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(newsockfd, buffer, BUFFER_SIZE, 0) < 0) {
                printf("Error receiving data\n");
                exit(1);
            }

            sscanf(buffer, "%lf %lf %d", &angle, &distance, &speed);

            x = speed * cos(angle);
            y = speed * sin(angle);

            printf("Robot should move %d units forward at an angle of %.2lf degrees.\n", speed, angle * 180 / M_PI);
            printf("The robot should end up at coordinates (%d, %d).\n", x, y);

            send(newsockfd, "OK", 3, 0);
        }

        close(newsockfd);
    }

    return 0;
}