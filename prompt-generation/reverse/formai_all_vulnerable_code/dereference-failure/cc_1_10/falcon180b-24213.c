//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove leading/trailing whitespace
    char *trimmed_url = url;
    while (isspace(*trimmed_url)) {
        trimmed_url++;
    }
    int length = strlen(trimmed_url);
    while (isspace(trimmed_url[length - 1])) {
        trimmed_url[--length] = '\0';
    }

    // Check if URL is valid
    if (is_valid_url(trimmed_url)) {
        printf("URL is valid.\n");
    } else {
        printf("URL is invalid.\n");
    }

    return 0;
}

// Function to check if URL is valid
int is_valid_url(char *url) {
    // Check if URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7)!= 0 && strncmp(url, "https://", 8)!= 0) {
        return 0;
    }

    // Check if URL contains any invalid characters
    char *invalid_chars = "!@#$%^&*()_+-=[]{}|;:,.<>? ";
    while (*url) {
        if (strchr(invalid_chars, *url)) {
            return 0;
        }
        url++;
    }

    return 1;
}