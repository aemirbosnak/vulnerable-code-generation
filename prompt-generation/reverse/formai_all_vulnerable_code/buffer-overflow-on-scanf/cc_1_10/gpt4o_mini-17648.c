//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_URL_LENGTH (MAX_URL_LENGTH + 1)

const char *reserved_chars = "!*'();:@&=+$,/?#[]";

// Function to check if a character is a reserved character
int is_reserved_char(char c) {
    return strchr(reserved_chars, c) != NULL;
}

// Function to escape a character
void escape_char(char c, char *output, int *index) {
    sprintf(output + (*index), "%%%02X", (unsigned char)c);
    *index += 3; // Increment by 3 for %XX format
}

// Function to sanitize the URL
void sanitize_url(const char *url, char *sanitized_url) {
    int url_len = strlen(url);
    int output_index = 0;

    for (int i = 0; i < url_len; i++) {
        char c = url[i];

        // Check for valid ASCII range and reserved characters
        if (isalnum(c) || is_reserved_char(c)) {
            sanitized_url[output_index++] = c; // Normal character
        } else if (isspace(c)) {
            // Convert spaces to %20
            escape_char(' ', sanitized_url, &output_index);
        } else {
            // Escape other invalid characters
            escape_char(c, sanitized_url, &output_index);
        }
    }
    sanitized_url[output_index] = '\0'; // Null-terminate the sanitized URL
}

// Function to demo sanitization
void demo_sanitization() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[SANITIZED_URL_LENGTH];

    printf("Enter a URL to sanitize (up to %d characters):\n", MAX_URL_LENGTH);
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0; // Remove trailing newline

    sanitize_url(url, sanitized_url);
    
    printf("Sanitized URL:\n%s\n", sanitized_url);
}

// Main function
int main() {
    printf("Welcome to the C URL Sanitizer! 🌍\n");
    printf("Let's tidy up your URLs with flair!\n");

    int continue_sanitizing = 1;
    while (continue_sanitizing) {
        demo_sanitization();
        
        char choice;
        printf("Do you want to sanitize another URL? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); // Clear stdin
        continue_sanitizing = (choice == 'y' || choice == 'Y');
    }

    printf("Thank you for using the C URL Sanitizer! 🎉\n");
    return 0;
}