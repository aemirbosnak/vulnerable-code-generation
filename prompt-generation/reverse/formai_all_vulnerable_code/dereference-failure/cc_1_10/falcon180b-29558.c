//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define RECEIVE_TIMEOUT 5 // seconds

void print_error(const char* message) {
    perror(message);
    exit(1);
}

void print_usage(const char* program_name) {
    printf("Usage: %s <server_address> <port>\n", program_name);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char* server_address = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strcasecmp(buffer, "quit\n") == 0) {
            break;
        }

        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            print_error("send");
        }
    }

    close(sockfd);
    return 0;
}