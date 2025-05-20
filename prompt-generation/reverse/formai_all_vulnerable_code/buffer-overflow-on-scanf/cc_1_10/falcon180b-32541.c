//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize URL
void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH);

    // Copy the URL to the sanitized URL
    while (url[i]) {
        if (isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '/' || url[i] == '?') {
            sanitized_url[j++] = url[i];
        }
        i++;
    }

    // Add the protocol to the sanitized URL
    if (strncmp(sanitized_url, "http://", 7)!= 0 && strncmp(sanitized_url, "https://", 8)!= 0) {
        strcat(sanitized_url, "http://");
        j += 7;
    }

    // Remove any trailing slash from the sanitized URL
    if (sanitized_url[j-1] == '/') {
        sanitized_url[j-1] = '\0';
        j--;
    }

    // Copy the sanitized URL to the original URL
    strcpy(url, sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get user input for URL
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}