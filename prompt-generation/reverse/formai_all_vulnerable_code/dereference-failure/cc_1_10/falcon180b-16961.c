//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

// Function to check if a character is valid for a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || strchr("!$&'()*+,-./:;=?@[\\]^_`{|}~", c)!= NULL) {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LEN * sizeof(char));
    char* sanitized_url_ptr = sanitized_url;
    int url_len = strlen(url);

    // Copy the URL to the sanitized URL buffer
    for (int i = 0; i < url_len; i++) {
        char c = url[i];

        // Check if the character is valid for a URL
        if (is_valid_url_char(c)) {
            // Copy the character to the sanitized URL buffer
            strncat(sanitized_url_ptr, &c, 1);
            sanitized_url_ptr++;
        }
    }

    // Add the null terminator to the sanitized URL buffer
    strncat(sanitized_url_ptr, "", 1);

    // Return the sanitized URL
    return sanitized_url;
}

int main() {
    char* url = "http://example.com/path?query=string#fragment";
    char* sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}