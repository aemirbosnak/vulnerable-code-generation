//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[100];
    int opt = 1;
    int on = 1;
    int off = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <on|off>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "on") == 0) {
        on = 1;
        off = 0;
    } else if (strcmp(argv[1], "off") == 0) {
        on = 0;
        off = 1;
    } else {
        fprintf(stderr, "Invalid argument: %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    printf("Waiting for connection...\n");

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection accepted.\n");

        while (1) {
            n = read(sockfd, buffer, sizeof(buffer));
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("Received: %s\n", buffer);

            if (strcmp(buffer, "turnon") == 0) {
                if (on == 0) {
                    printf("Turning on the lights...\n");
                    on = 1;
                    off = 0;
                } else if (off == 1) {
                    printf("Turning off the lights...\n");
                    on = 0;
                    off = 1;
                }
            } else if (strcmp(buffer, "turnoff") == 0) {
                if (on == 1) {
                    printf("Turning off the lights...\n");
                    on = 0;
                    off = 1;
                } else if (off == 0) {
                    printf("Turning on the lights...\n");
                    on = 1;
                    off = 0;
                }
            } else {
                printf("Invalid command: %s\n", buffer);
            }

            printf("Sending response...\n");
            sprintf(buffer, "Response: %s\n", on == 1? "on" : "off");
            write(sockfd, buffer, strlen(buffer));
            printf("Response sent.\n");
        }

        close(sockfd);
        break;
    }

    return 0;
}