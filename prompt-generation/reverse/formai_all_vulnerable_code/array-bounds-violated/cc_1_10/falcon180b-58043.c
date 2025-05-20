//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 512
#define IMAP_SERVER "localhost"
#define IMAP_PORT 143

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, IMAP_SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char buffer[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        fgets(buffer, MAX_COMMAND_LENGTH, stdin);
        send(sock, buffer, strlen(buffer), 0);

        char response[MAX_COMMAND_LENGTH];
        int bytes_received = recv(sock, response, MAX_COMMAND_LENGTH, 0);
        if (bytes_received <= 0) {
            printf("Error receiving response\n");
            exit(1);
        }
        response[bytes_received] = '\0';
        printf("%s\n", response);
    }

    close(sock);
    return 0;
}