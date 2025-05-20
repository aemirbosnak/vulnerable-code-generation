//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char buffer[BUFSIZE];
    char command[BUFSIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Bind socket to port
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        // Accept a connection
        if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n)) < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Receive data from client
        bzero(buffer, BUFSIZE);
        n = recv(newsockfd, buffer, BUFSIZE - 1, 0);
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);

        // Parse command
        sscanf(buffer, "%s", command);
        if (strcmp(command, "ON") == 0) {
            printf("Turning lights ON...\n");
            sleep(1);
            printf("Lights turned ON!\n");
        } else if (strcmp(command, "OFF") == 0) {
            printf("Turning lights OFF...\n");
            sleep(1);
            printf("Lights turned OFF!\n");
        } else if (strcmp(command, "TOGGLE") == 0) {
            printf("Toggling lights...\n");
            sleep(1);
            printf("Lights toggled!\n");
        } else {
            printf("Invalid command!\n");
        }

        // Close socket
        close(newsockfd);
    }

    return 0;
}