//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// This function checks if a given character is valid for a URL
int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

// This function sanitizes a given URL
char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int sanitized_url_length = 0;

    // Copy the scheme and colon
    sanitized_url_length += sprintf(sanitized_url, "%s://", url);

    // Copy the rest of the URL
    char *rest_of_url = url + strlen("://");
    while (*rest_of_url!= '\0') {
        if (is_valid_url_char(*rest_of_url)) {
            sanitized_url_length += sprintf(sanitized_url + sanitized_url_length, "%c", *rest_of_url);
        } else {
            sanitized_url_length += sprintf(sanitized_url + sanitized_url_length, "%%%02X", (int) *rest_of_url);
        }
        rest_of_url++;
    }

    // Add a null terminator
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}