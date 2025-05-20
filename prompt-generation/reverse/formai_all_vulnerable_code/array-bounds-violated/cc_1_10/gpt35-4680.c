//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Function to check if a character is a valid URL character */
bool isValidURLChar(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '/' || c == ':' || c == '?' || c == '&' || c == '=' || c == '-') {
        return true;
    }
    return false;
}

/* Function to sanitize a given URL */
char* sanitizeURL(char* url) {
    int len = strlen(url);
    int i, j;

    /* Allocating memory for the sanitized url */
    char* sanitized = (char*)malloc((len+1)*sizeof(char));
    memset(sanitized, 0, (len+1)*sizeof(char));

    /* Sanitizing the url by removing invalid characters */
    for(i = 0, j = 0; i < len; i++) {
        if(isValidURLChar(url[i])) {
            sanitized[j++] = url[i];
        }
    }

    return sanitized;
}

int main() {
    /* Reading the URL from user input */
    char url[1000];
    printf("Enter the URL: ");
    fgets(url, sizeof(url), stdin);
    url[strlen(url)-1] = '\0';  // Removing the newline character at the end

    /* Sanitizing the URL */
    char* sanitizedURL = sanitizeURL(url);

    /* Printing the sanitized URL */
    printf("Sanitized URL: %s\n", sanitizedURL);

    /* Freeing the memory allocated for the sanitized URL */
    free(sanitizedURL);

    return 0;
}