//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function to sanitize user input by removing special characters
void sanitize_input(char *input) {
    char sanitized[MAX_INPUT_LENGTH];
    int j = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';
    strcpy(input, sanitized);
}

// Function to display a menu and get user choice
int display_menu() {
    int choice;
    printf("Menu:\n");
    printf("1. Enter a new user input\n");
    printf("2. Display sanitized input\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear input buffer
    return choice;
}

// Main function
int main() {
    char user_input[MAX_INPUT_LENGTH] = {'\0'};
    char sanitized_input[MAX_INPUT_LENGTH] = {'\0'};
    int menu_choice;

    while (1) {
        menu_choice = display_menu();
        
        switch (menu_choice) {
            case 1:
                printf("Enter your input (max %d characters): ", MAX_INPUT_LENGTH - 1);
                fgets(user_input, sizeof(user_input), stdin);

                // Remove newline character from fgets
                user_input[strcspn(user_input, "\n")] = '\0';

                sanitize_input(user_input);
                strcpy(sanitized_input, user_input);
                printf("Input sanitized successfully.\n");
                break;

            case 2:
                if (strlen(sanitized_input) > 0) {
                    printf("Sanitized input: %s\n", sanitized_input);
                } else {
                    printf("No sanitized input available. Please enter input first.\n");
                }
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please select an option between 1 to 3.\n");
        }
        
        printf("\n");
    }

    return 0;
}