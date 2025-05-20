//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_URL_LENGTH 2048

// Function prototypes
void sanitize_url(const char *original_url, char *sanitized_url);
int is_valid_char(char c);
void handle_error(const char *message);
void print_shocked(const char *url, const char *sanitized);

// Main function
int main() {
    char original_url[MAX_URL_LENGTH];
    char sanitized_url[SANITIZED_URL_LENGTH];

    printf("😱 Enter the URL to sanitize: ");
    fgets(original_url, MAX_URL_LENGTH, stdin);

    // Remove newline character from input
    size_t length = strlen(original_url);
    if (original_url[length - 1] == '\n') {
        original_url[length - 1] = '\0';
    }

    printf("🔍 Original URL: %s\n", original_url);

    // Sanitize the URL
    sanitize_url(original_url, sanitized_url);

    // Print the result
    print_shocked(original_url, sanitized_url);

    return 0;
}

// Function to sanitize the URL
void sanitize_url(const char *original_url, char *sanitized_url) {
    int index = 0;

    for (const char *p = original_url; *p != '\0'; ++p) {
        if (is_valid_char(*p)) {
            if (index < SANITIZED_URL_LENGTH - 1) {
                sanitized_url[index++] = *p;
            } else {
                handle_error("Sanitized URL exceeded maximum length!");
            }
        } else {
            printf("⚠️  Disallowed character detected: '%c'\n", *p);
        }
    }
    sanitized_url[index] = '\0';
}

// Check if the character is a valid URL character
int is_valid_char(char c) {
    // Allowed characters: alphanumeric, '.', '-', '_', '~', ':', '/', '?', '#', '[', ']', '@', '!', '$', '&', "'", '(', ')', '*', '+', ',', ';', '=', '%'
    return (isalnum(c) || c == '.' || c == '-' || c == '_' || c == '~' || c == ':' || c == '/' || 
            c == '?' || c == '#' || c == '[' || c == ']' || c == '@' || c == '!' || 
            c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || 
            c == '+' || c == ',' || c == ';' || c == '=' || c == '%');
}

// Error handling function
void handle_error(const char *message) {
    fprintf(stderr, "❌ ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

// Print the shocked output
void print_shocked(const char *url, const char *sanitized) {
    printf("🔒 Sanitized URL: %s\n", sanitized);
    if (strcmp(url, sanitized) != 0) {
        printf("😲 Whoa! You had some naughty characters in your URL! 🚫\n");
    } else {
        printf("😎 Everything looks good! No naughty characters found!\n");
    }
}