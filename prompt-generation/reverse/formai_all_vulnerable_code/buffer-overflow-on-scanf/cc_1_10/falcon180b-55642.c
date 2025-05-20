//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
    int i;
    for (i = 0; url[i]!= '\0'; i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

int sanitize_url(char* url) {
    int i, j;
    char sanitized_url[MAX_URL_LENGTH];
    sanitized_url[0] = '\0';
    j = 0;
    for (i = 0; url[i]!= '\0'; i++) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
    return j;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    int sanitized_url_length = sanitize_url(url);

    if (sanitized_url_length == 0) {
        printf("Invalid URL\n");
    } else {
        printf("Sanitized URL: %s\n", url);
    }

    return 0;
}