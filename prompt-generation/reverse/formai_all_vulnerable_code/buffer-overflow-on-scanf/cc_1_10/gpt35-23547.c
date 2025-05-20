//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: detailed
/*
 * C URL Sanitizer Example Program
 * This program will take input URL and sanitize it by removing any malicious characters and symbols
 * Written By: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given character is an alpha-numeric character or not
int isAlphanum(char c) {
    return isalnum(c) || c == '-' || c == '_' || c == '.';
}

// Function to sanitize the URL by removing any malicious characters and symbols
void sanitizeUrl(char *url) {
    int i, j = 0;  // i: iterator for loop, j: index for sanitized URL
    char *tempUrl;
    tempUrl = (char *)malloc(strlen(url) + 1);  // Allocate memory for temp URL
    if (tempUrl == NULL) {
        printf("Error: Memory not allocated.\n");
        exit(1);
    }

    // Iterate over each character of the URL and sanitize it
    for (i = 0; url[i] != '\0'; i++) {
        if (isAlphanum(url[i])) {
            tempUrl[j++] = url[i];
        }
    }
    tempUrl[j] = '\0';  // Add null-terminator at the end of sanitized URL

    // Copy the sanitized URL back to original URL
    strcpy(url, tempUrl);

    // Free memory allocated to temp URL
    free(tempUrl);
}

int main() {
    char url[1000];

    // Input URL from user
    printf("Enter URL: ");
    scanf("%[^\n]s", url);
    getchar();  // To consume the newline character

    // Sanitize URL
    sanitizeUrl(url);

    // Output the sanitized URL
    printf("\nSanitized URL: %s\n", url);

    return 0;
}