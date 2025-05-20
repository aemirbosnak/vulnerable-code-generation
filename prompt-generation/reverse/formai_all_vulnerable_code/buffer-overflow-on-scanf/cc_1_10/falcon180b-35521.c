//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

// Function to remove non-alphanumeric characters from a string
void sanitize_url(char *url) {
    int i, j;
    char sanitized_url[MAX_URL_LENGTH];
    sanitized_url[0] = '\0';

    // Copy alphanumeric characters to the sanitized URL
    for (i = 0; i < strlen(url); i++) {
        if (isalnum(url[i])) {
            strncat(sanitized_url, &url[i], 1);
        }
    }

    // Replace multiple dots with a single dot
    for (i = 0; i < strlen(sanitized_url); i++) {
        if (sanitized_url[i] == '.') {
            for (j = i + 1; j < strlen(sanitized_url); j++) {
                if (sanitized_url[j] == '.') {
                    strncpy(&sanitized_url[j], &sanitized_url[j + 1], strlen(sanitized_url) - j);
                    sanitized_url[strlen(sanitized_url) - 1] = '\0';
                    break;
                }
            }
            break;
        }
    }

    // Replace the original URL with the sanitized URL
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get a URL from the user
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}