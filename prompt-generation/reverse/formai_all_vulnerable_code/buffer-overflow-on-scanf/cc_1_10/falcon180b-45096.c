//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char* sanitize_url(char* url) {
    int i, j, k;
    char* sanitized_url;
    char* hex_digits = "0123456789ABCDEF";

    // Check if URL is valid
    if (!url || strlen(url) == 0) {
        return NULL;
    }

    // Allocate memory for sanitized URL
    sanitized_url = malloc(MAX_URL_LENGTH);
    if (!sanitized_url) {
        return NULL;
    }

    // Initialize sanitized URL with empty string
    strcpy(sanitized_url, "");

    // Copy URL to sanitized URL, replacing invalid characters with their hexadecimal representation
    for (i = 0, j = 0; url[i]; i++) {
        if (isalnum(url[i]) || url[i] == '-') {
            sanitized_url[j++] = url[i];
        } else {
            sprintf(&sanitized_url[j], "%%%02X", url[i]);
            j += 3;
        }
    }

    // Add terminating null character to sanitized URL
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char* input_url;
    char* sanitized_url;

    // Prompt user for URL to sanitize
    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    // Sanitize URL
    sanitized_url = sanitize_url(input_url);

    // Print sanitized URL
    if (sanitized_url) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}