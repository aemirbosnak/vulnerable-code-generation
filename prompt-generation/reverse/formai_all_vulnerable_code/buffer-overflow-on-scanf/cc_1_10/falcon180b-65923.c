//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LEN 2048

// Function to check if a character is valid for a URL
bool is_valid_url_char(char c) {
    return (isalnum(c) || (c == '.') || (c == '-') || (c == '_') || (c == '~'));
}

// Function to sanitize a URL
void sanitize_url(char* url) {
    char* start = url;
    char* end = url + strlen(url);
    char* dst = url;

    // Check if URL is empty
    if (url[0] == '\0') {
        return;
    }

    // Check if URL is already sanitized
    if (is_valid_url_char(*url) && is_valid_url_char(*(end - 1))) {
        return;
    }

    // Encode non-ASCII characters
    while (start < end) {
        if (!is_valid_url_char(*start)) {
            sprintf(dst, "%%%02X", (unsigned char)*start);
            dst += 3;
        } else {
            *dst++ = *start;
        }
        start++;
    }
    *dst = '\0';
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}