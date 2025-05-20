//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048 // Maximum length of a URL

int is_valid_url_character(char c) {
    if (isalnum(c)) {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i = 0;
    int j = 0;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j] = tolower(url[i]);
            i++;
            j++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char *url = "https://www.example.com/path/to/page?query=string#fragment";
    char *sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}