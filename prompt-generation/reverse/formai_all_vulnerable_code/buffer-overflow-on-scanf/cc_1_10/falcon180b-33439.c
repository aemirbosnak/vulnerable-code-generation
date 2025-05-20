//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int main() {
    char username[64];
    char password[64];
    char hostname[256];
    int port;
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int response_length;
    int status;
    char *token;

    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter the IMAP server hostname: ");
    scanf("%s", hostname);
    printf("Enter the IMAP server port: ");
    scanf("%d", &port);

    status = imap_connect(hostname, port, username, password, &response, &response_length);
    if (status!= 0) {
        printf("Error connecting to server: %s\n", response);
        return 1;
    }

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        status = imap_send_command(command, &response, &response_length);
        if (status!= 0) {
            printf("Error sending command: %s\n", response);
            continue;
        }

        token = strtok(response, " ");
        if (token == NULL) {
            printf("Unexpected response: %s\n", response);
            continue;
        }

        if (strcmp(token, "OK") == 0) {
            printf("Command successful.\n");
        } else if (strcmp(token, "NO") == 0) {
            printf("Command failed.\n");
        } else {
            printf("Unexpected response: %s\n", response);
        }
    }

    return 0;
}

int imap_connect(const char *hostname, int port, const char *username, const char *password, char **response, int *response_length) {
    char command[MAX_COMMAND_LENGTH];
    int status;

    snprintf(command, MAX_COMMAND_LENGTH, "LOGIN \"%s\" \"%s\"", username, password);
    status = imap_send_command(command, response, response_length);
    if (status!= 0) {
        return status;
    }

    return 0;
}

int imap_send_command(const char *command, char **response, int *response_length) {
    int status;
    char buffer[MAX_RESPONSE_LENGTH];
    char *ptr;

    status = imap_write(command, strlen(command));
    if (status!= 0) {
        return status;
    }

    status = imap_read(buffer, MAX_RESPONSE_LENGTH);
    if (status!= 0) {
        return status;
    }

    *response = buffer;
    *response_length = status;

    ptr = strchr(*response, '\r');
    if (ptr!= NULL) {
        *ptr = '\0';
    }

    return 0;
}

int imap_write(const char *data, int length) {
    return write(1, data, length);
}

int imap_read(char *buffer, int length) {
    return read(0, buffer, length);
}