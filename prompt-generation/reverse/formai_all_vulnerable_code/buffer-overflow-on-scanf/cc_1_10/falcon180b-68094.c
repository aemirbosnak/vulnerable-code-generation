//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

/*
 * Function to check if a character is a valid URL character
 */
int is_valid_url_char(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' ||
        c == '&' || c == '=' || c == '+' || c == '%' || c == '@' || c == '$' ||
        c == ';' || c == ':' || c == ',' || c == '!' || c == '*' || c == '(' ||
        c == ')' || c == '"' || c == '\'') {
        return 1;
    }
    return 0;
}

/*
 * Function to sanitize a URL by removing invalid characters
 */
void sanitize_url(char* url) {
    int i, j;
    char sanitized_url[MAX_URL_LENGTH];
    sanitized_url[0] = '\0';
    i = 0;
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            strncat(sanitized_url, &url[i], 1);
        }
        i++;
    }
    strcpy(url, sanitized_url);
}

/*
 * Function to validate a URL by checking if it starts with "http://" or "https://"
 */
int validate_url(char* url) {
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    if (validate_url(url)) {
        printf("Valid URL: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }
    return 0;
}