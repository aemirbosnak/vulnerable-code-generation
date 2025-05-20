//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c)) {
        return 1;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || c == '+' || c == '$' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void sanitize_url(char *url) {
    int i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH) {
        if (!is_valid_url_character(url[i])) {
            url[i] = '%';
            i += 2;
        } else {
            i++;
        }
    }
    url[i] = '\0';
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    if (!is_valid_url(url)) {
        printf("Invalid URL!\n");
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Valid URL!\n");
    }
    return 0;
}