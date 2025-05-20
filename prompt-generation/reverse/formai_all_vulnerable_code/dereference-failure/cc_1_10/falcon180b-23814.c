//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c == '-') ||
        (c == '.') ||
        (c == '_')) {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(strlen(url) + 1);
    int i = 0;
    for (i = 0; url[i]!= '\0'; i++) {
        if (is_alphanumeric(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            int hex_digit = 0;
            if (isdigit(url[i])) {
                hex_digit = url[i] - '0';
            } else if (isupper(url[i])) {
                hex_digit = 10 + url[i] - 'A';
            } else {
                hex_digit = 10 + url[i] - 'a';
            }
            sanitized_url[i] = hex_digit < 10? hex_digit + '0' : hex_digit + 'A' - 10;
        }
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    char* url = argv[1];
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}