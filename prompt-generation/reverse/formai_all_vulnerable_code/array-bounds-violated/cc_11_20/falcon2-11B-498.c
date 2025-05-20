//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        if ((n = accept(sockfd, NULL, NULL)) < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("Accepted connection from %s\n", inet_ntoa(serv_addr.sin_addr));

        while ((n = recv(sockfd, buffer, BUFSIZE, 0)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
            if (strcmp(buffer, "turn on") == 0) {
                printf("Turning on light\n");
                // Code to turn on light goes here
            } else if (strcmp(buffer, "turn off") == 0) {
                printf("Turning off light\n");
                // Code to turn off light goes here
            } else if (strcmp(buffer, "get status") == 0) {
                printf("Light status: %s\n", "on"? "on" : "off");
                // Code to get light status goes here
            } else {
                printf("Invalid command: %s\n", buffer);
            }
        }

        if (n < 0) {
            perror("recv failed");
            exit(1);
        }

        close(sockfd);
    }

    return 0;
}