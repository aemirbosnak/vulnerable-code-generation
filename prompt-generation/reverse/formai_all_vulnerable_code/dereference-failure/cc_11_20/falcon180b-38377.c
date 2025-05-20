//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a character is valid in a URL
bool is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '!' ||
        c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' ||
        c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' ||
        c == '%' || c == '?' || c == '/' || c == '\\' || c == '^' || c == '`' ||
        c == '{' || c == '}' || c == '|' || c == '[' || c == ']' || c == '~') {
        return true;
    }
    return false;
}

// Function to sanitize a URL
char* sanitize_url(const char* url) {
    char* sanitized_url = malloc(strlen(url) + 1);
    int sanitized_url_len = 0;

    // Copy over valid characters
    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[sanitized_url_len++] = url[i];
        }
    }

    // Add % encoding for invalid characters
    for (int i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            sprintf(&sanitized_url[sanitized_url_len], "%%%02X", url[i]);
            sanitized_url_len += 3;
        }
    }

    // Null terminate the sanitized URL
    sanitized_url[sanitized_url_len] = '\0';

    return sanitized_url;
}

int main() {
    char* url = "http://example.com/path?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("%s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}