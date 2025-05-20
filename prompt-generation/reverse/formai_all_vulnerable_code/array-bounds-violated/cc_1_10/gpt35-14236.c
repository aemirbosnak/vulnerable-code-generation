//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given character is valid
int is_valid(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') || c == '.' || c == '-' || c == '/')
        return 1;
    else
        return 0;
}

// Function to sanitize a given URL
void sanitize_url(char* url) {
    int len = strlen(url);

    // Allocate memory for new copy of url
    char* new_url = (char*)malloc(len + 1);
    if (!new_url) {
        printf("Error: could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Loop through each character of the url and copy valid characters to new_url
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if (is_valid(url[i])) {
            new_url[j] = url[i];
            j++;
        }
    }
    new_url[j] = '\0';

    // Copy new_url back to url
    strcpy(url, new_url);

    // Free memory allocated for new_url
    free(new_url);
}

int main() {
    char url[100];

    // Get input url from user
    printf("Enter URL: ");
    fgets(url, 100, stdin);

    // Remove newline character from url
    if (url[strlen(url) - 1] == '\n') {
        url[strlen(url) - 1] = '\0';
    }

    printf("Sanitizing URL...\n");

    // Sanitize url
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}