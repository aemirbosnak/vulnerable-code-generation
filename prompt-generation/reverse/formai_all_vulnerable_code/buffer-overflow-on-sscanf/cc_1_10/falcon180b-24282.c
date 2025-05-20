//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_COMMANDS 10

char *commands[MAX_COMMANDS] = {"CAPABILITY", "LOGIN", "LOGOUT", "SELECT", "CHECK",
                                "FETCH", "STORE", "SEARCH", "COPY", "MOVE"};

int main(int argc, char *argv[]) {
    char host[64] = "localhost";
    int port = 143;
    char username[64] = "user";
    char password[64] = "password";

    printf("Connecting to IMAP server...\n");

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, stdin)) {
        line[strcspn(line, "\r\n")] = '\0';

        if (strncmp(line, "CONNECT", 7) == 0) {
            sscanf(line, "CONNECT %s:%d", host, &port);
        } else if (strncmp(line, "USERNAME", 8) == 0) {
            sscanf(line, "USERNAME %s", username);
        } else if (strncmp(line, "PASSWORD", 8) == 0) {
            sscanf(line, "PASSWORD %s", password);
        } else if (strncmp(line, "LOGOFF", 6) == 0) {
            printf("Disconnecting from IMAP server...\n");
            break;
        } else {
            int command_index = -1;
            for (int i = 0; i < MAX_COMMANDS; i++) {
                if (strcasecmp(commands[i], line) == 0) {
                    command_index = i;
                    break;
                }
            }

            if (command_index!= -1) {
                printf("Sending command: %s\n", line);
            } else {
                printf("Unknown command: %s\n", line);
            }
        }
    }

    return 0;
}