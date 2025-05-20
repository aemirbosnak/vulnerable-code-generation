#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

void process_message(char username[MAX_USERNAME_LENGTH], char message[MAX_MESSAGE_LENGTH]) {
    char buffer[64];

    printf("Enter your username: ");
    if (sscanf(fgets(buffer, sizeof(buffer), stdin) , "%s", username) != 1) {
        printf("Invalid username format. Please try again.\n");
        return;
    }

    printf("Connected as %s.\n", username);
    printf("Enter a message: ");
    if (sscanf(fgets(buffer, sizeof(buffer), stdin) , "%s", message) != 1) {
        printf("Invalid message format. Please try again.\n");
        return;
    }

    printf("Message received: %s\n", message);

    // Vulnerable code: not checking the length of the message before scanning it into buffer
    int number;
    if (sscanf(message, "%d", &number) == 1) {
        printf("Received integer: %d\n", number);
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    process_message(username, message);

    return 0;
}
