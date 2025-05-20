//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char buffer[BUFFSIZE];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return 1;
    }

    listen(sockfd, 5);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        return 1;
    }

    while (1) {
        bzero(buffer, BUFFSIZE);
        n = recv(newsockfd, buffer, BUFFSIZE, 0);
        if (n < 0) {
            perror("ERROR reading from socket");
            return 1;
        }

        buffer[n] = '\0';

        printf("Received: %s\n", buffer);

        if (strcmp(buffer, "on") == 0) {
            printf("Turning on...\n");
            sleep(1);
            printf("Turning off...\n");
            sleep(1);
            printf("Turning on...\n");
            sleep(1);
            printf("Turning off...\n");
            sleep(1);
        } else if (strcmp(buffer, "off") == 0) {
            printf("Turning off...\n");
            sleep(1);
            printf("Turning on...\n");
            sleep(1);
            printf("Turning off...\n");
            sleep(1);
            printf("Turning on...\n");
            sleep(1);
        } else if (strcmp(buffer, "toggle") == 0) {
            printf("Toggling...\n");
            sleep(1);
            printf("Toggling...\n");
            sleep(1);
            printf("Toggling...\n");
            sleep(1);
            printf("Toggling...\n");
            sleep(1);
        } else if (strcmp(buffer, "brightness") == 0) {
            printf("Changing brightness...\n");
            sleep(1);
            printf("Changing brightness...\n");
            sleep(1);
            printf("Changing brightness...\n");
            sleep(1);
            printf("Changing brightness...\n");
            sleep(1);
        } else if (strcmp(buffer, "hue") == 0) {
            printf("Changing hue...\n");
            sleep(1);
            printf("Changing hue...\n");
            sleep(1);
            printf("Changing hue...\n");
            sleep(1);
            printf("Changing hue...\n");
            sleep(1);
        } else if (strcmp(buffer, "saturation") == 0) {
            printf("Changing saturation...\n");
            sleep(1);
            printf("Changing saturation...\n");
            sleep(1);
            printf("Changing saturation...\n");
            sleep(1);
            printf("Changing saturation...\n");
            sleep(1);
        } else {
            printf("Invalid command\n");
        }

        printf("Sending response: %s\n", buffer);
        send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    close(newsockfd);
    return 0;
}