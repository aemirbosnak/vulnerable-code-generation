//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 256

/**
 * Function to check if a character is a valid alphanumeric character
 * or a valid separator character
 */
bool is_valid_character(char c) {
    if (c >= '0' && c <= '9') return true;
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c == '-' || c == '_' || c == '.' || c == '/' || c == ':') return true;
    return false;
}

/**
 * Function to sanitize a given URL string
 * Returns true if the string was sanitized, false otherwise
 */
bool sanitize_url(char *url) {
    char *out = (char*)malloc(MAX_URL_LENGTH * sizeof(char));
    if (out == NULL) {
        printf("Error: Unable to allocate memory!\n");
        return false;
    }

    int i = 0, j = 0;
    while (url[i] != '\0' && j < MAX_URL_LENGTH - 1) {
        if (is_valid_character(url[i])) {
            out[j] = url[i];
            j++;
        }
        i++;
    }
    out[j] = '\0';

    if (strcmp(url, out) != 0) {
        printf("Input URL was sanitized to: %s\n", out);
        strcpy(url, out);
        free(out);
        return true;
    }

    free(out);
    return false;
}

/**
 * Main function to test the URL sanitizer
 */
int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter URL to sanitize: ");
    scanf("%s", url);

    if (sanitize_url(url)) {
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("No need to sanitize URL.\n");
    }

    return 0;
}