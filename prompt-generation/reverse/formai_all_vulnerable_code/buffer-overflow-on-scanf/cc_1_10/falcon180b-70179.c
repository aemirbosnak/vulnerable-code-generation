//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' || c == '?' || c == '^' || c == '`' || c == '{' || c == '}' || c == '|') {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char* url) {
    int i, j;
    char buffer[MAX_URL_LENGTH];
    strcpy(buffer, url);
    i = 0;
    while (buffer[i]!= ':') {
        if (buffer[i] == '/') {
            buffer[i] = '%';
            i++;
            while (isdigit(buffer[i])) {
                i++;
            }
        }
        i++;
    }
    j = 0;
    while (buffer[i]!= '\0') {
        if (is_valid_url_character(buffer[i])) {
            url[j] = buffer[i];
            j++;
        }
        i++;
    }
    url[j] = '\0';
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}