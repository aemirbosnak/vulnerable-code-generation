//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 25
#define SMTP_SERVER "smtp.gmail.com"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int n;
    int bytes_sent;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, BUFFER_SIZE, stdin);

        n = strlen(command);
        if (command[n-1] == '\n') {
            command[n-1] = '\0';
        }

        bytes_sent = send(sock, command, n, 0);
        if (bytes_sent == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        memset(buffer, 0, BUFFER_SIZE);
        n = 0;

        while ((n = recv(sock, buffer+n, BUFFER_SIZE-n, 0)) > 0) {
            buffer[n] = '\0';
        }

        printf("Response: %s\n", buffer);

        if (strcmp(command, "QUIT") == 0) {
            break;
        }
    }

    close(sock);
    return 0;
}