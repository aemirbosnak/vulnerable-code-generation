//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    char buffer[BUF_SIZE];
    int n;
    char *ptr;
    int i, j;
    int signal_strength;
    int max_strength = 0;
    int min_strength = 999;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Socket creation failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)server->h_addr, server->h_length) == -1) {
        fprintf(stderr, "Error: Connection failed\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n == 0) {
            fprintf(stderr, "Error: Connection closed\n");
            exit(1);
        }
        buffer[n] = '\0';
        fprintf(stdout, "Received: %s\n", buffer);

        ptr = strtok(buffer, " ");
        while (ptr!= NULL) {
            if (strcmp(ptr, "Signal") == 0) {
                ptr = strtok(NULL, " ");
                signal_strength = atoi(ptr);
                if (signal_strength > max_strength) {
                    max_strength = signal_strength;
                }
                if (signal_strength < min_strength) {
                    min_strength = signal_strength;
                }
            }
            ptr = strtok(NULL, " ");
        }
    }

    close(sockfd);
    return 0;
}