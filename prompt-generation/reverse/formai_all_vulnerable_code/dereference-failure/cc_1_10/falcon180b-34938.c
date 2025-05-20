//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
void sanitize_url(char *url) {
    // Remove any leading or trailing whitespace
    char *start = url;
    char *end = url + strlen(url) - 1;
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }

    // Remove any illegal characters
    char *ptr = start;
    while (*ptr) {
        if (!isalnum(*ptr) && *ptr!= '.' && *ptr!= '-' && *ptr!= '_') {
            *ptr = '\0';
        }
        ptr++;
    }

    // Remove any consecutive dots or dashes
    ptr = start;
    while (*ptr) {
        if (*ptr == '.' || *ptr == '-') {
            int count = 1;
            while (ptr[count] == *ptr && count < MAX_URL_LENGTH - 1) {
                count++;
            }
            if (count > 1) {
                memmove(ptr, ptr + count, strlen(ptr + count) + 1);
            }
        }
        ptr++;
    }

    // Remove any leading or trailing dots or dashes
    while (*start == '.' || *start == '-') {
        start++;
    }
    while (*end == '.' || *end == '-') {
        end--;
        *end = '\0';
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get input URL from user
    printf("Enter URL: ");
    scanf("%s", url);

    // Sanitize URL
    sanitize_url(url);

    // Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}