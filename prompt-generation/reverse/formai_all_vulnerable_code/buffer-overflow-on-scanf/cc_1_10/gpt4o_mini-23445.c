//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

// Function to check if a character is valid in a URL
int is_allowed_char(char c) {
    return strchr(ALLOWED_CHARACTERS, c) != NULL;
}

// Function to sanitize a URL by only allowing valid characters
void sanitize_url(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_allowed_char(input[i])) {
            output[j++] = input[i];
        } else {
            // Encode the invalid character in %XX format
            j += sprintf(output + j, "%%%02X", (unsigned char)input[i]);
        }
    }
    output[j] = '\0'; // Null-terminate the sanitized string
}

// Function to read multiple URLs from the user
void read_urls(char urls[][MAX_URL_LENGTH], int *count) {
    printf("Enter the number of URLs to sanitize: ");
    scanf("%d", count);
    getchar(); // consume the newline character after integer input
    
    for (int i = 0; i < *count; i++) {
        printf("Enter URL %d: ", i + 1);
        fgets(urls[i], MAX_URL_LENGTH, stdin);
        // Remove the newline character
        size_t len = strlen(urls[i]);
        if (len > 0 && urls[i][len - 1] == '\n') {
            urls[i][len - 1] = '\0';
        }
    }
}

// Function to sanitize all given URLs and store results
void sanitize_urls(char urls[][MAX_URL_LENGTH], char sanitized[][MAX_URL_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        sanitize_url(urls[i], sanitized[i]);
    }
}

// Function to output sanitized URLs
void output_sanitized_urls(char sanitized[][MAX_URL_LENGTH], int count) {
    printf("\nSanitized URLs:\n");
    for (int i = 0; i < count; i++) {
        printf("Sanitized URL %d: %s\n", i + 1, sanitized[i]);
    }
}

int main() {
    char urls[100][MAX_URL_LENGTH]; // Original input URLs
    char sanitized[100][MAX_URL_LENGTH]; // Sanitized output URLs
    int count = 0; // Number of URLs to sanitize

    // Read URLs from the user
    read_urls(urls, &count);

    // Sanitize URLs
    sanitize_urls(urls, sanitized, count);

    // Output the sanitized URLs
    output_sanitized_urls(sanitized, count);

    return 0;
}