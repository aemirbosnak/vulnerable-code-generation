//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

/*
 * Check if a character is a valid URL character.
 */
int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?'|| c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    } else {
        return 0;
    }
}

/*
 * Sanitize a URL by removing any invalid characters and encoding any special characters.
 */
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int sanitized_url_length = 0;

    while (*url) {
        if (is_valid_url_character(*url)) {
            sanitized_url[sanitized_url_length++] = *url;
        } else {
            char hex_value[3];
            sprintf(hex_value, "%%%02X", (unsigned char)*url);
            strncat(sanitized_url, hex_value, MAX_URL_LENGTH - sanitized_url_length - 1);
            sanitized_url_length += 3;
        }
        url++;
    }

    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char* unsanitized_url = "http://example.com/path/to/page?query=string&param=value#fragment";
    char* sanitized_url = sanitize_url(unsanitized_url);

    printf("Unsanitized URL: %s\n", unsanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}