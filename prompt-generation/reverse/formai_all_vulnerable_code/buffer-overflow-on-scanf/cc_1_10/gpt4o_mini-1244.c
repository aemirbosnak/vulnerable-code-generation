//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_SANITIZED_LENGTH 2048

// Function prototypes
void sanitize_url(const char *url, char *sanitized_url);
int is_safe_character(char c);
void print_menu();
void execute_choice(int choice);
char *get_user_input();

// Entry point of the program
int main() {
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character after scanf
        execute_choice(choice);
    } while (choice != 3);

    return 0;
}

// Function to print the menu
void print_menu() {
    printf("\n--- URL Sanitizer ---\n");
    printf("1. Sanitize a URL\n");
    printf("2. Show Instructions\n");
    printf("3. Exit\n");
}

// Function to execute the user's choice
void execute_choice(int choice) {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_SANITIZED_LENGTH];

    switch (choice) {
        case 1:
            printf("Enter the URL to sanitize: ");
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = '\0';  // Remove newline character

            sanitize_url(url, sanitized_url);
            printf("Sanitized URL: %s\n", sanitized_url);
            break;
        case 2:
            printf("Instructions: Input a URL to sanitize it by removing unsafe characters.\n");
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

// Function to sanitize the URL
void sanitize_url(const char *url, char *sanitized_url) {
    int position = 0;

    for (int i = 0; url[i] != '\0' && position < MAX_SANITIZED_LENGTH - 1; i++) {
        if (is_safe_character(url[i])) {
            sanitized_url[position++] = url[i];
        } else {
            // Replace unsafe character with '_'
            sanitized_url[position++] = '_';
        }
    }

    sanitized_url[position] = '\0';  // Null-terminate the sanitized string
}

// Function to check if a character is safe for a URL
int is_safe_character(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == ':' || c == '/' || c == '?' || c == '&' || c == '=') {
        return 1; // Safe character
    }
    return 0; // Unsafe character
}

// Function to get user input (used in more complex scenarios)
char *get_user_input() {
    static char input[MAX_URL_LENGTH];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    return input;
}