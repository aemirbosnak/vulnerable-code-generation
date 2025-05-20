//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    struct sockaddr_in server_addr;
    char hostname[64];
    int port;
    char username[64];
    char password[64];
    char command[MAX_COMMAND_LENGTH];
    char buffer[BUFFER_SIZE];
    int nbytes;

    // Get hostname, port, username, and password from user input
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port: ");
    scanf("%d", &port);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Connect to server
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        printf("Error: failed to create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: failed to connect to server\n");
        exit(1);
    }

    // Authenticate with server
    sprintf(command, "LOGIN %s %s", username, password);
    send(fd, command, strlen(command), 0);
    nbytes = recv(fd, buffer, BUFFER_SIZE, 0);
    buffer[nbytes] = '\0';
    if (strncmp(buffer, "OK", 2)!= 0) {
        printf("Error: failed to authenticate with server\n");
        exit(1);
    }

    // Send commands to server
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        send(fd, command, strlen(command), 0);

        nbytes = recv(fd, buffer, BUFFER_SIZE, 0);
        buffer[nbytes] = '\0';
        printf("%s\n", buffer);
    }

    close(fd);
    return 0;
}