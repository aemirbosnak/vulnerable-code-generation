//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL by removing invalid characters
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int sanitized_url_length = 0;

    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[sanitized_url_length++] = url[i];
        }
    }

    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

// Function to print usage instructions for the program
void print_usage() {
    printf("Usage:./program URL\n");
}

// Main function of the program
int main(int argc, char** argv) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    char* url = argv[1];
    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}