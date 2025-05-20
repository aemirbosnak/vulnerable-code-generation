//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 2048 // Maximum length of URL

int isValidChar(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    return 0;
}

void sanitize(char* url) {
    int i = 0, j = 0;
    char sanitized[MAX_LENGTH];

    // Remove any leading/trailing whitespace
    while (isspace(url[i])) {
        i++;
    }
    while (isspace(url[j])) {
        j--;
    }

    // Copy valid characters to sanitized string
    while (i <= j) {
        if (isValidChar(url[i])) {
            sanitized[j++] = url[i++];
        } else {
            i++;
        }
    }
    sanitized[j] = '\0';

    // Copy sanitized string back to original string
    strcpy(url, sanitized);
}

int main() {
    char url[MAX_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}