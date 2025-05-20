//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;
    int bytes_sent;
    int bytes_received;
    char *message;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        printf("Enter a message to send to the server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
        if (bytes_sent == -1) {
            printf("Error sending message: %s\n", strerror(errno));
            exit(1);
        }

        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving message: %s\n", strerror(errno));
            exit(1);
        }
        buffer[bytes_received] = '\0';
        message = strdup(buffer);
        printf("Message received from server: %s\n", message);
        free(message);
    }

    close(sockfd);
    return 0;
}