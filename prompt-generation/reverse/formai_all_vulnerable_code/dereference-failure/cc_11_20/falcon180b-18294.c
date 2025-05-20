//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE 1024
#define MAX_USERNAME 64
#define MAX_PASSWORD 64
#define MAX_COMMAND 64
#define MAX_RESPONSE 1024

#define POP3_PORT 110
#define POP3_USER "user"
#define POP3_PASS "password"

char username[MAX_USERNAME+1] = "";
char password[MAX_PASSWORD+1] = "";
char host[MAX_LINE+1] = "";

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }
    strcpy(host, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, host, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char auth_response[MAX_RESPONSE+1] = "";
    char response[MAX_RESPONSE+1] = "";

    sprintf(response, "USER %s\r\n", username);
    send(sock, response, strlen(response), 0);

    if (recv(sock, auth_response, MAX_RESPONSE, 0) <= 0) {
        printf("Error receiving authentication response\n");
        close(sock);
        return 1;
    }

    if (strncmp(auth_response, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        close(sock);
        return 1;
    }

    sprintf(response, "PASS %s\r\n", password);
    send(sock, response, strlen(response), 0);

    if (recv(sock, auth_response, MAX_RESPONSE, 0) <= 0) {
        printf("Error receiving authentication response\n");
        close(sock);
        return 1;
    }

    if (strncmp(auth_response, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        close(sock);
        return 1;
    }

    char command[MAX_COMMAND+1] = "";
    while (1) {
        printf("Enter command (quit to exit): ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) {
            break;
        }
        sprintf(response, "%s\r\n", command);
        send(sock, response, strlen(response), 0);

        if (recv(sock, auth_response, MAX_RESPONSE, 0) <= 0) {
            printf("Error receiving response\n");
            close(sock);
            return 1;
        }

        printf("Response: %s", auth_response);
    }

    close(sock);
    return 0;
}