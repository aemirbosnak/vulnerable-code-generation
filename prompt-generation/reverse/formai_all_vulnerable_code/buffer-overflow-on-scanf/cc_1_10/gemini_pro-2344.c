//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <curl/curl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_URL_LEN 1000

// Function to sanitize a URL
int sanitize_url(char *url, char *sanitized_url) {
    // Check if the URL is valid
    if (url == NULL || strlen(url) == 0) {
        return -1;
    }

    // Trim leading and trailing whitespace
    while (*url == ' ') {
        url++;
    }
    while (strlen(url) > 0 && url[strlen(url) - 1] == ' ') {
        url[strlen(url) - 1] = '\0';
    }

    // Check if the URL is too long
    if (strlen(url) > MAX_URL_LEN) {
        return -1;
    }

    // Check if the URL contains any illegal characters
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] < 32 || url[i] > 126) {
            return -1;
        }
    }

    // Copy the sanitized URL to the destination buffer
    strcpy(sanitized_url, url);

    return 0;
}

int main() {
    // Initialize cURL
    curl_global_init(CURL_GLOBAL_ALL);

    // Set up the URL and sanitized URL buffers
    char url[MAX_URL_LEN];
    char sanitized_url[MAX_URL_LEN];

    // Get the URL from the user
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    // Sanitize the URL
    if (sanitize_url(url, sanitized_url) == -1) {
        printf("Invalid URL.\n");
        return -1;
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Cleanup cURL
    curl_global_cleanup();

    return 0;
}