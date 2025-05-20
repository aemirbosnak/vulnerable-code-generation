#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void readMessage() {
    char buffer[20];
    printf("Enter your message (max 20 chars): ");
    scanf("%s", buffer);
}

void displayMessage(char *message) {
    printf("Received message: %s\n", message);
}

void processMessage(char *message) {
    char keyword[5];
    printf("Processing message: %s\n", message);
    sscanf(message, "%4s", keyword);
    if (strcmp(keyword, "HELLO") == 0) {
        printf("Hello! Nice to meet you.\n");
    } else {
        printf("Invalid command. Use 'HELLO' to greet.\n");
    }
}

int main() {
    char buffer[512];
    while (1) {
        readMessage();
        strcpy(buffer, "");
        strncat(buffer, "\033[2K\r", 6);
        strcat(buffer, "Received message: ");
        strcat(buffer, getenv("INPUT_MESSAGE"));
        if (getenv("INPUT_MESSAGE")) {
            processMessage(getenv("INPUT_MESSAGE"));
            printf(buffer);
            system("printf \\012");
        }
    }
    return 0;
}
