//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 100

int main(int argc, char *argv[]) {
    char host[MAX_LINE_LENGTH] = "imap.example.com";
    int port = 993;
    char username[MAX_LINE_LENGTH] = "user@example.com";
    char password[MAX_LINE_LENGTH] = "password";
    char command[MAX_COMMAND_LENGTH] = "LOGIN";
    char response[MAX_LINE_LENGTH] = "";
    int i, j;
    char c;
    int done = 0;

    printf("Welcome to the IMAP client!\n");

    printf("Enter host (default is imap.example.com): ");
    scanf("%s", host);

    printf("Enter port (default is 993): ");
    scanf("%d", &port);

    printf("Enter username (default is user@example.com): ");
    scanf("%s", username);

    printf("Enter password: ");
    for (i = 0; i < strlen(password); i++) {
        c = getchar();
        password[i] = c;
    }

    printf("Enter command (default is LOGIN): ");
    for (i = 0; i < strlen(command); i++) {
        c = getchar();
        command[i] = toupper(c);
    }

    printf("Connecting to %s:%d\n", host, port);
    if (connect(0, host, port) == -1) {
        printf("Error connecting to host\n");
        return 1;
    }

    printf("Sending command: %s\n", command);
    if (send(0, command, strlen(command), 0) == -1) {
        printf("Error sending command\n");
        return 1;
    }

    while (!done) {
        memset(response, 0, MAX_LINE_LENGTH);
        if (recv(0, response, MAX_LINE_LENGTH, 0) == -1) {
            printf("Error receiving response\n");
            return 1;
        }
        printf("Received response: %s\n", response);

        for (i = 0; i < strlen(response); i++) {
            if (response[i] == '\r' || response[i] == '\n') {
                response[i] = '\0';
            }
        }

        if (strncmp(response, "OK", 2) == 0) {
            done = 1;
        } else if (strncmp(response, "BAD", 3) == 0) {
            printf("Authentication failed\n");
            return 1;
        } else if (strncmp(response, "CAPABILITY", 10) == 0) {
            printf("Server capabilities: %s\n", response + 10);
        } else {
            printf("Unknown response: %s\n", response);
        }
    }

    printf("IMAP client exiting\n");
    return 0;
}