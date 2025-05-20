//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Custom error message for invalid URLs
#define INVALID_URL_ERROR "Error: Invalid URL! Please enter a valid URL to sanitize."

// Function to sanitize a URL
char *sanitize_url(char *url) {
    // Check if the URL is valid
    if (!url || strlen(url) == 0) {
        fprintf(stderr, INVALID_URL_ERROR);
        return NULL;
    }

    // Initialize Curl
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Could not initialize Curl!\n");
        return NULL;
    }

    // Set the URL to sanitize
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Perform a HEAD request to fetch the sanitized URL
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: Could not sanitize URL! (%s)\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return NULL;
    }

    // Get the sanitized URL from the response headers
    char *location = NULL;
    res = curl_easy_getinfo(curl, CURLINFO_REDIRECT_URL, &location);
    if (res != CURLE_OK || !location) {
        fprintf(stderr, "Error: Could not retrieve sanitized URL!\n");
        curl_easy_cleanup(curl);
        return NULL;
    }

    // Copy the sanitized URL to a new string
    char *sanitized_url = strdup(location);

    // Cleanup Curl
    curl_easy_cleanup(curl);

    // Return the sanitized URL
    return sanitized_url;
}

// Function to print the sanitized URL
void print_sanitized_url(char *url) {
    if (!url) {
        printf("Invalid URL! Please enter a valid URL to sanitize.\n");
    } else {
        printf("Sanitized URL: %s\n", url);
    }
}

int main() {
    // Get the input URL from the user
    char input_url[256];
    printf("Enter the URL to sanitize: ");
    scanf("%s", input_url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(input_url);

    // Print the sanitized URL
    print_sanitized_url(sanitized_url);

    // Free the allocated memory
    free(sanitized_url);

    return 0;
}