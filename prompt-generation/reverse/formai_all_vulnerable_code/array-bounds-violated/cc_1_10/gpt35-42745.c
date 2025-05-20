//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: post-apocalyptic
// Post-Apocalyptic C URL Sanitizer

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

int main() {

    // Declare and initialize variables
    char url[MAX_URL_LENGTH];
    int i;

    // Get URL input from user
    printf("Enter URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove newline character from URL if present
    if (url[strlen(url)-1] == '\n') {
        url[strlen(url)-1] = '\0';
    }

    // Convert URL to lowercase
    for (i=0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    // Replace backslash with forward slash
    for (i=0; url[i]; i++) {
        if (url[i] == '\\') {
            url[i] = '/';
        }
    }

    // Remove any trailing slashes
    while (url[strlen(url)-1] == '/') {
        url[strlen(url)-1] = '\0';
    }

    // Remove any query parameters
    char* query = strchr(url, '?');
    if (query) {
        *query = '\0';
    }

    // Remove any fragments
    char* fragment = strchr(url, '#');
    if (fragment) {
        *fragment = '\0';
    }

    // Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}