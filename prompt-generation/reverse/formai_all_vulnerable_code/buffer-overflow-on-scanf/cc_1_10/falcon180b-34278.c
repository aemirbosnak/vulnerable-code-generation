//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

/*
 * Check if a character is a valid URL character.
 * Returns 1 if it is, 0 otherwise.
 */
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '+' || c == '=' || c == '&' || c == '%' || c == '$' || c == '?') {
        return 1;
    }
    return 0;
}

/*
 * Check if a string is a valid URL.
 * Returns 1 if it is, 0 otherwise.
 */
int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

/*
 * Sanitize a URL by removing invalid characters.
 * Returns a pointer to the sanitized URL.
 */
char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    j = 0;
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}