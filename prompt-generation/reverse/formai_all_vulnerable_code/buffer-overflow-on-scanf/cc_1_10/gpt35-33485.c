//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 500

// Function to check if a character is a valid URL character
int isValidChar(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.' || c == '/' || c == ':' || c == '-' || c == '_') {
        return 1;
    }
    return 0;
}

// Function to remove all invalid characters from the URL
void sanitizeURL(char* url) {
    int i, j;
    char* sanitizedURL = malloc(MAX_URL_LENGTH * sizeof(char));
    memset(sanitizedURL, 0, MAX_URL_LENGTH);
    
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (isValidChar(url[i])) {
            sanitizedURL[j++] = url[i];
        }
    }
    
    strcpy(url, sanitizedURL);
    free(sanitizedURL);
}

// Function to sanitize the URL recursively
void recursiveSanitizeURL(char* url) {
    char* temp = malloc(MAX_URL_LENGTH * sizeof(char));
    memset(temp, 0, MAX_URL_LENGTH);
    
    strcpy(temp, url);
    sanitizeURL(temp);
    
    if (strcmp(temp, url) != 0) {
        recursiveSanitizeURL(temp);
    } else {
        printf("Sanitized URL: %s\n", url);
    }
    
    free(temp);
}

int main() {
    char url[MAX_URL_LENGTH];
    
    printf("Enter a URL: ");
    scanf("%s", url);
    
    recursiveSanitizeURL(url);
    
    return 0;
}