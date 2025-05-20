//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if character is an alphabetic character
int isAlpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

// Function to check if character is a digit
int isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

// Function to check if character is a valid URL character
int isValidURLChar(char c) {
    if (isAlpha(c) || isDigit(c) || c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitizeURL(char* url) {
    // Allocate memory for buffer to hold sanitized URL
    char* sanitized = (char*)malloc(strlen(url)*sizeof(char));
    
    // Set index variables
    int i = 0;
    int j = 0;
    
    // Loop through each character in URL
    while (url[i]) {
        // Check if character is valid URL character
        if (isValidURLChar(url[i])) {
            // Copy character to sanitized URL buffer
            sanitized[j] = url[i];
            j++;
        }
        i++;
    }
    
    // Add terminating null character to sanitized URL buffer
    sanitized[j] = '\0';
    
    return sanitized;
}

int main() {
    // Get input URL from user
    char url[100];
    printf("Enter URL: ");
    scanf("%s", url);
    
    // Sanitize URL
    char* sanitized = sanitizeURL(url);
    
    // Print sanitized URL
    printf("Sanitized URL: %s\n", sanitized);
    
    // Free memory allocated for sanitized URL buffer
    free(sanitized);
    
    return 0;
}