//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize URL
void sanitize_url(char *url) {
    int i = 0, j = 0;
    char *clean_url = malloc(MAX_URL_LENGTH);
    if (clean_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Copy only valid characters to clean_url
    while (url[i]) {
        if (isalnum(url[i]) || url[i] == '-') {
            clean_url[j++] = tolower(url[i]);
        }
        i++;
    }
    clean_url[j] = '\0';

    // Replace consecutive dots with a single dot
    char *ptr = clean_url;
    while (*ptr) {
        if (*ptr == '.') {
            while (*(ptr + 1) == '.') {
                ptr++;
            }
        }
        ptr++;
    }

    // Remove trailing dot if present
    int len = strlen(clean_url);
    if (clean_url[len - 1] == '.') {
        clean_url[len - 1] = '\0';
    }

    // Check if the sanitized URL is valid
    if (strlen(clean_url) > 0 && clean_url[0]!= '.') {
        printf("Sanitized URL: %s\n", clean_url);
    } else {
        printf("Invalid URL.\n");
    }

    free(clean_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);

    return 0;
}