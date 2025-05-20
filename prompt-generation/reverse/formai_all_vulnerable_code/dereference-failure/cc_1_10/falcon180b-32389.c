//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == '?' || c == '@' || c == '[') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL by removing invalid characters
void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            url[j++] = url[i];
        }
        i++;
    }
    url[j] = '\0';
}

// Function to validate a URL by checking if it starts with "http://" or "https://"
int validate_url(char* url) {
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print an error message and exit the program
void error(char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        error("Usage:./url_sanitizer <url>");
    }

    char* url = argv[1];
    sanitize_url(url);

    if (!validate_url(url)) {
        error("Invalid URL");
    }

    printf("Sanitized URL: %s\n", url);
    return 0;
}