//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048
#define DISALLOWED_CHARS " <>\"{}|\\^~[]`"

bool is_disallowed_char(char c) {
    return strchr(DISALLOWED_CHARS, c) != NULL;
}

void sanitize_url(const char *url, char *sanitized_url) {
    size_t j = 0;
    for (size_t i = 0; i < strlen(url); i++) {
        char current_char = url[i];
        if (is_disallowed_char(current_char)) {
            // Replace disallowed characters with an underscore
            sanitized_url[j++] = '_';
        } else {
            sanitized_url[j++] = current_char;
        }
    }
    sanitized_url[j] = '\0';  // Null-terminate the sanitized URL
}

void display_menu() {
    printf("URL Sanitizer Program\n");
    printf("----------------------\n");
    printf("Please enter a URL to sanitize:\n");
}

void get_user_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove trailing newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    display_menu();

    get_user_input(url, sizeof(url));

    // Sanitize the URL
    sanitize_url(url, sanitized_url);

    // Display the original and sanitized URLs
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    printf("Would you like to sanitize another URL? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    while (choice == 'y' || choice == 'Y') {
        display_menu();
        get_user_input(url, sizeof(url));
        sanitize_url(url, sanitized_url);
        printf("Original URL: %s\n", url);
        printf("Sanitized URL: %s\n", sanitized_url);
        printf("Would you like to sanitize another URL? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the URL sanitizer!\n");
    
    return 0;
}