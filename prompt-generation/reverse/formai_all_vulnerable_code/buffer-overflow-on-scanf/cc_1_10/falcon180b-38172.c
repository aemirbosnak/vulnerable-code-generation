//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

char* sanitize_url(const char* input_url) {
    char* sanitized_url = NULL;
    size_t sanitized_url_len = 0;
    const char* p;
    char* q;

    // Check if input URL is valid
    if (input_url == NULL || strlen(input_url) == 0) {
        return NULL;
    }

    // Allocate memory for sanitized URL
    sanitized_url = (char*) malloc(MAX_URL_LEN * sizeof(char));
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Initialize variables
    sanitized_url_len = 0;
    p = input_url;

    // Loop through each character in input URL
    while (*p!= '\0') {
        // Check if character is allowed
        if (strchr(ALLOWED_CHARS, tolower(*p))!= NULL) {
            // Copy allowed character to sanitized URL
            q = &sanitized_url[sanitized_url_len];
            *q = tolower(*p);
            sanitized_url_len++;
        }
        p++;
    }

    // Add terminating null character to sanitized URL
    sanitized_url[sanitized_url_len] = '\0';

    // Return sanitized URL
    return sanitized_url;
}

int main() {
    char* input_url;
    char* sanitized_url;

    // Prompt user for input URL
    printf("Enter a URL: ");
    scanf("%s", input_url);

    // Sanitize input URL
    sanitized_url = sanitize_url(input_url);

    // Print sanitized URL
    if (sanitized_url!= NULL) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid input URL.\n");
    }

    // Free memory
    free(sanitized_url);

    return 0;
}