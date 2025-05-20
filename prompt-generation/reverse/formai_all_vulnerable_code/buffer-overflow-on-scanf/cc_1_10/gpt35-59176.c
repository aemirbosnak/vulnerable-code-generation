//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char username[BUFFER_SIZE], password[BUFFER_SIZE], server[BUFFER_SIZE];
    printf("Enter your email address: ");
    scanf("%s", username);

    printf("Enter your password (Note: password will be shown): ");
    scanf("%s", password);
    printf("Connecting to server...\n");
    printf("Enter POP3 server address: ");
    scanf("%s", server);
    printf("Connected to %s\n", server);

    char message[BUFFER_SIZE];
    sprintf(message, "USER %s\n", username);
    // send message to server
    printf("Sending: %s", message);

    // receive response from server
    char response[BUFFER_SIZE] = "+OK welcome to POP3 server";
    printf("Response: %s\n", response);

    sprintf(message, "PASS %s\n", password);
    // send message to server
    printf("Sending: %s", message);

    // receive response from server
    response[0] = '+';
    printf("Response: %s\n", response);

    // keep receiving messages from server until we quit
    while (1) {
        printf("Enter a command (QUIT to exit): ");
        scanf("%s", message);
        if (strcmp(message, "QUIT") == 0) {
            // send message to server
            printf("Sending: %s\n", message);

            // receive response from server
            response[0] = '+';
            printf("Response: %s\n", response);
            break;
        } else {
            // send message to server
            printf("Sending: %s\n", message);

            // receive response from server
            response[0] = '+';
            printf("Response: %s\n", response);
        }
    }

    printf("Disconnected from server\n");
    return 0;
}