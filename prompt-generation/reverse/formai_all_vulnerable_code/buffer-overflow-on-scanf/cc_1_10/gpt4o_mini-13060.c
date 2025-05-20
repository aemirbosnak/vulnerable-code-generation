//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function declarations
void get_string_input(char *input_string);
void configure_options(int *ignore_spaces, int *case_sensitive);
int is_palindrome(const char *input_string, int ignore_spaces, int case_sensitive);
void clean_string(const char *input_string, char *cleaned_string, int ignore_spaces, int case_sensitive);
void display_result(const char *input_string, int is_palindrome);

// Main Function
int main() {
    char input_string[MAX_LENGTH];
    int ignore_spaces = 0;
    int case_sensitive = 0;

    get_string_input(input_string);
    configure_options(&ignore_spaces, &case_sensitive);
    
    int palindrome_check = is_palindrome(input_string, ignore_spaces, case_sensitive);
    display_result(input_string, palindrome_check);

    return 0;
}

// Function to get user input string
void get_string_input(char *input_string) {
    printf("Enter a string to check for palindrome: ");
    fgets(input_string, MAX_LENGTH, stdin);
    // Remove the newline character if present
    size_t len = strlen(input_string);
    if (len > 0 && input_string[len - 1] == '\n') {
        input_string[len - 1] = '\0';
    }
}

// Function to configure options for palindrome checking
void configure_options(int *ignore_spaces, int *case_sensitive) {
    int choice;

    printf("Configuration Options:\n");
    printf("1. Ignore spaces (1 - Yes, 0 - No): ");
    scanf("%d", ignore_spaces);

    printf("2. Case sensitive (1 - Yes, 0 - No): ");
    scanf("%d", case_sensitive);
}

// Function to check if the input string is a palindrome
int is_palindrome(const char *input_string, int ignore_spaces, int case_sensitive) {
    char cleaned_string[MAX_LENGTH];
    clean_string(input_string, cleaned_string, ignore_spaces, case_sensitive);

    int len = strlen(cleaned_string);
    for (int i = 0; i < len / 2; i++) {
        if (cleaned_string[i] != cleaned_string[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Function to clean the input string based on user options
void clean_string(const char *input_string, char *cleaned_string, int ignore_spaces, int case_sensitive) {
    int j = 0;
    for (int i = 0; input_string[i] != '\0'; i++) {
        char current_char = input_string[i];

        // Ignore spaces
        if (ignore_spaces && isspace(current_char)) {
            continue;
        }

        // Convert to lower case if not case sensitive
        if (!case_sensitive) {
            current_char = tolower(current_char);
        }

        cleaned_string[j++] = current_char;
    }
    cleaned_string[j] = '\0'; // Null terminate the cleaned string
}

// Function to display the result
void display_result(const char *input_string, int is_palindrome) {
    if (is_palindrome) {
        printf("\"%s\" is a palindrome.\n", input_string);
    } else {
        printf("\"%s\" is not a palindrome.\n", input_string);
    }
}