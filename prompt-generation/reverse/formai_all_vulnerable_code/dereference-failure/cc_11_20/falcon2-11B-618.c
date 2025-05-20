//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int port;
    struct sockaddr_in server_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    if (port < 1 || port > 65535) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char buf[1024];
    bzero(buf, sizeof(buf));

    while (fgets(buf, sizeof(buf), stdin)!= NULL) {
        if (strncmp(buf, "quit", 4) == 0) {
            break;
        } else if (strncmp(buf, "help", 4) == 0) {
            fprintf(stderr, "Usage: %s <port>\n", argv[0]);
            fprintf(stderr, "  or\n");
            fprintf(stderr, "   -h\t\tPrint this help message\n");
            fprintf(stderr, "   -q\t\tQuit the program\n");
            continue;
        } else if (strncmp(buf, "port", 4) == 0) {
            fprintf(stderr, "Port number: %d\n", port);
            continue;
        } else if (strncmp(buf, "host", 4) == 0) {
            fprintf(stderr, "Server hostname: 127.0.0.1\n");
            continue;
        } else if (strncmp(buf, "socket", 6) == 0) {
            fprintf(stderr, "Socket file descriptor: %d\n", sockfd);
            continue;
        } else if (strncmp(buf, "connect", 6) == 0) {
            fprintf(stderr, "Connect to server: 127.0.0.1:%d\n", port);
            continue;
        } else if (strncmp(buf, "data", 4) == 0) {
            fprintf(stderr, "Data sent to server: %s\n", buf);
            continue;
        } else {
            fprintf(stderr, "Unknown command: %s\n", buf);
            continue;
        }
    }

    close(sockfd);
    return 0;
}