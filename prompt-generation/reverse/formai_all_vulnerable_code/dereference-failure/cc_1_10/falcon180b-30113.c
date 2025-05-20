//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is a valid URL character
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' || c == '%') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int sanitized_url_index = 0;

    // Copy the first character of the URL
    sanitized_url[sanitized_url_index++] = url[0];

    // Loop through the rest of the URL characters
    for (int i = 1; i < strlen(url); i++) {
        char c = url[i];

        // Check if the character is a valid URL character
        if (is_valid_url_char(c)) {
            // Copy the character to the sanitized URL
            sanitized_url[sanitized_url_index++] = c;
        } else {
            // Encode the character as % followed by its hexadecimal value
            char hex_value[3];
            sprintf(hex_value, "%02X", (unsigned char)c);
            strcat(sanitized_url, "%");
            strcat(sanitized_url, hex_value);
        }
    }

    // Add a null terminator to the end of the sanitized URL
    sanitized_url[sanitized_url_index] = '\0';

    return sanitized_url;
}

int main() {
    char* input_url = "https://www.example.com/path/to/page?query=string&param2=value#fragment";
    char* sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}