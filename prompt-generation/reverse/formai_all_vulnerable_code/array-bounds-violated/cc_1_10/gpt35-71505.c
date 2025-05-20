//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 50

int main() {
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH]; // Array to store emails
    int num_emails = 0; // Number of emails currently stored in array

    // Loop through user input until 'quit' command is entered
    while (1) {
        char input[MAX_EMAIL_LENGTH+10]; // +10 for extra characters in fgets buffer
        printf("Enter an email address (or 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        if (input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }

        // Check if user entered 'quit'
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Check if email address is valid
        int at_symbol_index = -1;
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == '@') {
                at_symbol_index = i;
                break;
            }
        }
        if (at_symbol_index == -1) {
            printf("Invalid email address. Missing '@' symbol.\n");
            continue;
        }
        if (at_symbol_index == 0) {
            printf("Invalid email address. Missing username.\n");
            continue;
        }
        if (at_symbol_index == strlen(input)-1) {
            printf("Invalid email address. Missing domain.\n");
            continue;
        }

        // Add email address to array
        strcpy(emails[num_emails], input);
        num_emails++;
        printf("Email address added!\n");
    }

    // Print all email addresses stored in array
    printf("Current email list:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\n", emails[i]);
    }

    return 0;
}