//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_char(char c) {
    return (isalnum(c) || 
            c == '-' || 
            c == '_' || 
            c == '.' || 
            c == '~' || 
            c == ':' || 
            c == '/' || 
            c == '?' || 
            c == '#' || 
            c == '[' || 
            c == ']' || 
            c == '@' || 
            c == '!' || 
            c == '$' || 
            c == '&' || 
            c == '\'' || 
            c == '(' || 
            c == ')' || 
            c == '*' || 
            c == '+' || 
            c == ',' || 
            c == ';' || 
            c == '=');
}

// Cyberpunk style function to sanitize URL
void sanitize_url(const char *input_url, char *sanitized_url) {
    char *ptr = sanitized_url;
    
    while (*input_url) {
        if (is_valid_char(*input_url)) {
            *ptr++ = *input_url;
        } else {
            // Instead of removing invalid chars, encode them
            sprintf(ptr, "%%%02X", (unsigned char)(*input_url));
            ptr += 3; // Move pointer past the encoded part
        }
        input_url++;
    }
    *ptr = '\0'; // Null-terminate the sanitized URL
}

int main() {
    char input_url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH * 3]; // To accommodate encodings
    
    printf("\n===============================\n");
    printf("    Cyberpunk URL Sanitizer    \n");
    printf("===============================\n");

    // Input the URL
    printf("Enter the URL to sanitize (max 2048 chars):\n> ");
    
    // Safely read input
    if (fgets(input_url, sizeof(input_url), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Strip newline character if present
    size_t length = strlen(input_url);
    if (input_url[length - 1] == '\n') {
        input_url[length - 1] = '\0';
    }

    // Sanitize the URL
    sanitize_url(input_url, sanitized_url);
    
    // Output the results
    printf("\nSanitized URL:\n> %s\n", sanitized_url);
    
    printf("Safe travels through the dark alleys of the net!\n");
    
    return 0;
}