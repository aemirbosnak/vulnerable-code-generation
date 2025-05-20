//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *message = "Hello, World! ";
    char buffer[BUFFER_SIZE];
    int nbytes;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, message, strlen(message), 0);

    do {
        nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (nbytes == 0) {
            printf("Server disconnected\n");
            break;
        }

        buffer[nbytes] = '\0';

        printf("Received: %s", buffer);
    } while (1);

    close(sockfd);

    return 0;
}