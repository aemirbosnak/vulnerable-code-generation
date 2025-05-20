//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 25

int main() {

    char password[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    char password_input[MAX_PASSWORD_LENGTH];
    int password_count = 0;
    int attempts = 0;
    int max_attempts = 3;
    int password_found = 0;

    printf("Welcome to your password manager!\n");

    while (1) {
        printf("\nWhat would you like to do? (add/check/reset/exit): ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            if (password_count == MAX_PASSWORDS) {
                printf("Sorry, you have reached the maximum number of passwords you can store.\n");
            } else {
                printf("Enter new password: ");
                scanf("%s", password[password_count]);
                password_count++;
                printf("Password added!\n");
            }
        } else if (strcmp(input, "check") == 0) {
            if (password_count == 0) {
                printf("No passwords stored.\n");
            } else {
                printf("Enter password name: ");
                scanf("%s", password_input);
                for (int i = 0; i < MAX_PASSWORDS; i++) {
                    if (strcmp(password_input, password[i]) == 0) {
                        printf("Password found: %s\n", password[i]);
                        password_found = 1;
                        break;
                    }
                }
                if (!password_found) {
                    printf("Password not found.\n");
                }
            }
        } else if (strcmp(input, "reset") == 0) {
            if (attempts >= max_attempts) {
                printf("Too many incorrect attempts. Please try again later.\n");
            } else {
                printf("Enter master password: ");
                scanf("%s", password_input);
                if (strcmp(password_input, "masterpassword123") == 0) {
                    printf("Password manager reset!\n");
                    password_count = 0;
                    attempts = 0;
                } else {
                    printf("Incorrect password. Please try again.\n");
                    attempts++;
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input, please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}