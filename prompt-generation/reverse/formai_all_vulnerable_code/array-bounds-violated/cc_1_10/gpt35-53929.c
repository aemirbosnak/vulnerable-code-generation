//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitizeURL(char* url) {
    // Creating a new string to hold the sanitized URL
    char* sanitized_url = malloc(strlen(url) + 1);
    int j = 0;

    for(int i = 0; i < strlen(url); i++) {
        char current_char = url[i];

        // Converting all characters to lowercase
        if(isalpha(current_char)) {
            current_char = tolower(current_char);
        }

        // Removing all characters except letters and numbers
        if(isalnum(current_char)) {
            sanitized_url[j] = current_char;
            j++;
        }
    }

    // Adding null terminator to the end of the sanitized URL
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char url[100];

    // Getting URL input from user
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);

    // Removing newline character from the end of the URL
    url[strlen(url) - 1] = '\0';

    // Sanitizing the URL
    char* sanitized_url = sanitizeURL(url);

    // Printing the Sanitized URL
    printf("Sanitized URL: %s", sanitized_url);

    // Freeing the memory allocated for the sanitized URL
    free(sanitized_url);

    return 0;
}