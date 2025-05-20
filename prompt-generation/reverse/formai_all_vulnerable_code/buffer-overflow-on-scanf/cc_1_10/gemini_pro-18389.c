//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Forward declarations
static int is_safe_character(char c);
static char* sanitize_url(char* url);
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);

int main() {
    // Get the URL from the user
    printf("Enter the URL to sanitize: ");
    char url[1024];
    scanf("%s", url);

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the allocated memory
    free(sanitized_url);

    return 0;
}

// Checks if a character is safe for use in a URL
static int is_safe_character(char c) {
    // According to RFC 3986, the following characters are safe to use in a URL:
    // - A-Z
    // - a-z
    // - 0-9
    // - -
    // - .
    // - _
    // - ~

    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') ||
           (c == '-') ||
           (c == '.') ||
           (c == '_') ||
           (c == '~');
}

// Sanitizes a URL by removing unsafe characters and encoding unsafe characters
static char* sanitize_url(char* url) {
    // Allocate memory for the sanitized URL
    char* sanitized_url = malloc(strlen(url) + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Initialize the sanitized URL
    strcpy(sanitized_url, "");

    // Iterate over the characters in the URL
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        // If the character is safe, append it to the sanitized URL
        if (is_safe_character(c)) {
            char* temp = malloc(strlen(sanitized_url) + 2);
            sprintf(temp, "%s%c", sanitized_url, c);
            free(sanitized_url);
            sanitized_url = temp;
        }
        // If the character is unsafe, encode it and append it to the sanitized URL
        else {
            char encoded_c[4];
            sprintf(encoded_c, "%%%02X", c);
            char* temp = malloc(strlen(sanitized_url) + strlen(encoded_c) + 1);
            sprintf(temp, "%s%s", sanitized_url, encoded_c);
            free(sanitized_url);
            sanitized_url = temp;
        }
    }

    // Return the sanitized URL
    return sanitized_url;
}

// Callback function for curl_easy_perform()
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    // Get the user data
    FILE* file = (FILE*) userp;

    // Write the data to the file
    fwrite(contents, size, nmemb, file);

    // Return the number of bytes written
    return size * nmemb;
}