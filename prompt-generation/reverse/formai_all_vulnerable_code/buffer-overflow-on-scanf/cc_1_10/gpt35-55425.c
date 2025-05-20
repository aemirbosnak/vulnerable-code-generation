//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if given character is alphanumeric
int isAlphaNumeric(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return 1;
    }
    return 0;
}

// Helper function to remove special characters from string
void removeSpecialChars(char *str, int len) {
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isAlphaNumeric(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to sanitize URL
char* sanitizeURL(char *url) {
    // Remove trailing slashes
    int len = strlen(url);
    while (len > 0 && url[len-1] == '/') {
        url[--len] = '\0';
    }

    // Remove query string, if any
    char *qMarkPtr = strchr(url, '?');
    if (qMarkPtr != NULL) {
        *qMarkPtr = '\0';
    }

    // Remove special characters from the domain name
    char *protocol = strstr(url, "://");
    char *start;
    if (protocol != NULL) {
        start = protocol + 3;
    } else {
        start = url;
    }
    char *slashPtr = strchr(start, '/');
    if (slashPtr != NULL) {
        removeSpecialChars(start, slashPtr - start);
    } else {
        removeSpecialChars(start, strlen(start));
    }

    // Remove special characters from the path
    if (slashPtr != NULL) {
        char *pathStart = slashPtr;
        removeSpecialChars(pathStart, strlen(pathStart));
    }

    // Return sanitized URL
    return url;
}

// Driver code
int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);
    char *sanitizedURL = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitizedURL);
    return 0;
}