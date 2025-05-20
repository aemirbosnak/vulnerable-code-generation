//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *command = "LIST";

    if (argc < 4) {
        printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    if (argc >= 5) {
        username = argv[3];
    }

    if (argc >= 6) {
        password = argv[4];
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: Invalid hostname\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    printf("Connected to %s on port %s\n", argv[1], argv[2]);

    if (send(sock, username, strlen(username), 0) < 0) {
        printf("Error: Sending username failed\n");
        exit(1);
    }

    if (send(sock, password, strlen(password), 0) < 0) {
        printf("Error: Sending password failed\n");
        exit(1);
    }

    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Error: Sending command failed\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Receiving data failed\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(sock);
    exit(0);
}