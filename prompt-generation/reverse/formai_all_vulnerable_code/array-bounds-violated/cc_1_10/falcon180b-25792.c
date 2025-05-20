//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define SERVER "localhost"
#define PORT 110
#define USER "romeo"
#define PASS "juliet"

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    char username[50] = USER;
    char password[50] = PASS;
    char response[1024];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        memset(response, 0, sizeof(response));

        printf("Enter command: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(sock, buffer, strlen(buffer), 0);

        n = recv(sock, response, sizeof(response), 0);

        response[n] = '\0';

        printf("Server response: %s\n", response);

        if (strncmp(response, "+OK", 4) == 0) {
            printf("Authentication successful\n");
            break;
        } else if (strncmp(response, "-ERR", 5) == 0) {
            printf("Authentication failed\n");
            exit(0);
        }
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        memset(response, 0, sizeof(response));

        printf("Enter command: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(sock, buffer, strlen(buffer), 0);

        n = recv(sock, response, sizeof(response), 0);

        response[n] = '\0';

        printf("Server response: %s\n", response);

        if (strncmp(response, "+OK", 4) == 0) {
            printf("Command executed successfully\n");
        } else if (strncmp(response, "-ERR", 5) == 0) {
            printf("Error executing command\n");
        }
    }

    close(sock);

    return 0;
}