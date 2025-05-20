//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || c == '%' || c == '#' || c == '[') {
        return true;
    }
    return false;
}

bool is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_character(url[i])) {
            return false;
        }
        i++;
    }
    return true;
}

void sanitize_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_character(url[i])) {
            url[i] = '%';
            i++;
            url[i] = '2';
            i++;
            url[i] = '0';
        }
        i++;
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("The URL is valid.\n");
    } else {
        sanitize_url(url);
        printf("The sanitized URL is: %s\n", url);
    }

    return 0;
}