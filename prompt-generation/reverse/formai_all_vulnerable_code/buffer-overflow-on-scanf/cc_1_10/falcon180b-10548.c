//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '%') {
        return true;
    } else {
        return false;
    }
}

int sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char sanitized_url[MAX_URL_LENGTH];
    char c;

    while (url[i]) {
        c = tolower(url[i]);
        if (is_valid_url_character(c)) {
            sanitized_url[j++] = c;
        } else {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = (c >> 4) & 0x0F;
            sanitized_url[j++] = (c & 0x0F);
        }
        i++;
    }

    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);

    return strlen(url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    int sanitized_url_length = sanitize_url(url);

    printf("Sanitized URL: %s\n", url);
    printf("Sanitized URL Length: %d\n", sanitized_url_length);

    return 0;
}