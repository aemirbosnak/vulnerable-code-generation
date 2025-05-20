//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server address> <port number>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, '\0', BUFFER_SIZE);

        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strcasecmp(buffer, "QUIT") == 0) {
            send(sockfd, buffer, strlen(buffer), 0);
            break;
        } else {
            send(sockfd, buffer, strlen(buffer), 0);
        }

        memset(buffer, '\0', BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            printf("Error receiving data\n");
            return 1;
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}