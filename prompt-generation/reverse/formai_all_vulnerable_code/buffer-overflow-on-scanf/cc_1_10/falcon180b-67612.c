//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            url[i] = '%';
            i++;
            sprintf(&url[i], "%02X", (unsigned char)url[i]);
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    if (!is_valid_url(url)) {
        printf("Invalid URL!\n");
        return 1;
    }

    printf("Sanitized URL: ");
    sanitize_url(url);
    printf("%s\n", url);

    return 0;
}