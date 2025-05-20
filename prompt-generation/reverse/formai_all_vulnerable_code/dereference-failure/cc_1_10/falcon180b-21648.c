//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define SERVER_PORT 110
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int addrlen;
    char buffer[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];
    char response[MAX_LINE_LENGTH];
    int n;
    int len;
    fd_set readfds;
    time_t start_time;
    time_t end_time;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    portno = SERVER_PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("your_server_ip");
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        select(sockfd+1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &readfds)) {
            n = read(sockfd, buffer, MAX_LINE_LENGTH);
            if (n <= 0) {
                printf("Error: Could not read from server\n");
                exit(1);
            }

            buffer[n-1] = '\0';
            printf("%s", buffer);

            if (strstr(buffer, "+OK")) {
                printf("Logged in successfully\n");
            } else if (strstr(buffer, "-ERR")) {
                printf("Error: %s\n", buffer);
                exit(1);
            }
        }
    }

    close(sockfd);

    return 0;
}