//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    int sockfd, n;
    struct sockaddr_in serv_addr;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[1024];
    printf("Connected to server\n");
    while (1) {
        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Received: %s\n", buffer);
        char command[1024];
        scanf("%s", command);
        if (strcmp(command, "forward") == 0) {
            n = write(sockfd, "forward", 7);
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            printf("Sent: %s\n", buffer);
        } else if (strcmp(command, "backward") == 0) {
            n = write(sockfd, "backward", 8);
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            printf("Sent: %s\n", buffer);
        } else if (strcmp(command, "left") == 0) {
            n = write(sockfd, "left", 5);
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            printf("Sent: %s\n", buffer);
        } else if (strcmp(command, "right") == 0) {
            n = write(sockfd, "right", 6);
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            printf("Sent: %s\n", buffer);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}