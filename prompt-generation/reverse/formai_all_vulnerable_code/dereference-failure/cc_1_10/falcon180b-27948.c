//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 110

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_LINE];
    char line[MAX_LINE];
    char *ptr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname("localhost");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to POP3 server.\n");

    while (1) {
        bzero(buffer, MAX_LINE);
        n = read(sockfd, buffer, MAX_LINE);

        if (n <= 0) {
            printf("Connection closed by server.\n");
            break;
        }

        buffer[n] = '\0';

        printf("Received: %s", buffer);

        ptr = strtok(buffer, "\r\n");

        while (ptr!= NULL) {
            strcpy(line, ptr);

            if (strstr(line, "+OK")!= NULL) {
                printf("Server response: %s\n", line);
            } else if (strstr(line, "-ERR")!= NULL) {
                printf("Server error: %s\n", line);
            }

            ptr = strtok(NULL, "\r\n");
        }
    }

    close(sockfd);

    return 0;
}