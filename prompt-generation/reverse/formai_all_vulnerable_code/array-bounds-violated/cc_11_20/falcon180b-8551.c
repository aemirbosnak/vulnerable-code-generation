//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' || c == '?' || c == '/' || c == '\\' || c == '|' || c == '%' || c == '#' || c == '>' || c == '<' || c == '^' || c == '`' || c == '{' || c == '}' || c == '~' || c == '[') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    int url_length = strlen(url);

    // Remove leading and trailing spaces
    while (isspace(url[0])) {
        strcpy(url, &url[1]);
        url_length--;
    }
    while (isspace(url[url_length - 1])) {
        url[url_length - 1] = '\0';
        url_length--;
    }

    // Remove invalid characters
    char sanitized_url[MAX_URL_LENGTH];
    int sanitized_url_length = 0;
    for (int i = 0; i < url_length; i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[sanitized_url_length++] = url[i];
        }
    }
    sanitized_url[sanitized_url_length] = '\0';

    // Output the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    return 0;
}