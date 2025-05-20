//FormAI DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

// Global variables
char email[50] = "";
char password[50] = "";

// Function to get user input safely without buffer overflows
void get_input(char *input, int max_length) {
    fgets(input, max_length, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character from the input
}

// Function to check if the email format is valid
int is_valid_email(char *email) {
    int i;
    int at_symbol_count = 0;
    int dot_count = 0;

    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') at_symbol_count++;
        if (email[i] == '.') dot_count++;
    }

    if (at_symbol_count == 1 && dot_count >= 1) return 1;
    return 0;
}

// Function to send an email using SMTP protocol
void send_email(char *recipient, char *subject, char *message) {
    // TODO: Implement SMTP protocol to send the email
    printf("Email sent to %s with subject '%s' and message '%s'\n", recipient, subject, message);
}

int main() {
    // Get user input for email address and password
    printf("Enter your email address: ");
    get_input(email, 50);

    printf("Enter your password: ");
    get_input(password, 50);

    // Menu loop
    while (1) {
        char recipient[50] = "";
        char subject[50] = "";
        char message[MAX_INPUT] = "";
        int option;

        // Display options
        printf("\n1. Send Email\n");
        printf("2. Change Email Address\n");
        printf("3. Exit\n");

        // Get user choice
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        // Clear stdin
        getchar();

        // Perform action based on choice
        switch (option) {
            case 1: // Send Email
                // Get recipient email address
                printf("\nEnter recipient email address: ");
                get_input(recipient, 50);

                // Check if recipient email address is valid
                if (!is_valid_email(recipient)) {
                    printf("Invalid email address\n");
                    break;
                }

                // Get subject and message
                printf("Enter subject: ");
                get_input(subject, 50);

                printf("Enter message: ");
                get_input(message, MAX_INPUT);

                // Send email
                send_email(recipient, subject, message);

                break;
            case 2: // Change Email Address
                printf("\nEnter your new email address: ");
                get_input(email, 50);
                break;
            case 3: // Exit
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again\n");
                break;
        }
    }

    return 0;
}