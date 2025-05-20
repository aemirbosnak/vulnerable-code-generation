//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is valid for a URL
int isValidChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitizeURL(char* url) {
    int i = 0;
    int j = 0;
    char* sanitizedUrl = malloc(strlen(url) + 1);

    // Copy over valid characters to sanitized URL
    while (url[i]) {
        if (isValidChar(url[i])) {
            sanitizedUrl[j++] = url[i];
        }
        i++;
    }

    // Add %XX encoding for non-valid characters
    i = 0;
    while (sanitizedUrl[i]) {
        if (!isValidChar(sanitizedUrl[i])) {
            sprintf(&sanitizedUrl[i], "%%%02X", (int)sanitizedUrl[i]);
            i += 3;
        }
        i++;
    }

    // Add null terminator
    sanitizedUrl[j] = '\0';

    return sanitizedUrl;
}

int main() {
    char* url = "https://example.com/path/to/page?query=string#fragment";
    char* sanitizedUrl = sanitizeURL(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl);
    return 0;
}