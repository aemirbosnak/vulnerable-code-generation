//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define PORT 8080

int main() {
    int sockfd, valread, valwrite, new_socket, numbytes;
    struct sockaddr_in server, client;
    char buffer[MAX_BUFFER];
    char* username = "Alice";
    char* password = "password";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        new_socket = accept(sockfd, (struct sockaddr *) &client, (socklen_t *) &valread);
        if (new_socket < 0) {
            perror("Error on accepting");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        while ((numbytes = recv(new_socket, buffer, MAX_BUFFER, 0)) > 0) {
            printf("Received: %s\n", buffer);
            buffer[numbytes] = '\0';
            if (strcmp(buffer, "login") == 0) {
                if (strcmp(username, "Alice") == 0) {
                    printf("Login successful! Welcome, Alice.\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
            } else if (strcmp(buffer, "register") == 0) {
                if (strcmp(username, "Alice") == 0) {
                    printf("You are already registered, Alice.\n");
                } else {
                    printf("Registering new user...\n");
                    username = malloc(strlen(buffer) + 1);
                    strcpy(username, buffer);
                    printf("Username: %s\n", username);
                }
            } else if (strcmp(buffer, "create_room") == 0) {
                if (strcmp(username, "Alice") == 0) {
                    printf("Creating room...\n");
                    printf("Room name: %s\n", buffer);
                } else {
                    printf("You are not authorized to create rooms.\n");
                }
            } else if (strcmp(buffer, "join_room") == 0) {
                if (strcmp(username, "Alice") == 0) {
                    printf("Joining room...\n");
                    printf("Room name: %s\n", buffer);
                } else {
                    printf("You are not authorized to join rooms.\n");
                }
            } else if (strcmp(buffer, "send_message") == 0) {
                if (strcmp(username, "Alice") == 0) {
                    printf("Sending message...\n");
                    printf("Message: %s\n", buffer);
                } else {
                    printf("You are not authorized to send messages.\n");
                }
            } else {
                printf("Unknown command: %s\n", buffer);
            }
        }
        close(new_socket);
    }

    return 0;
}