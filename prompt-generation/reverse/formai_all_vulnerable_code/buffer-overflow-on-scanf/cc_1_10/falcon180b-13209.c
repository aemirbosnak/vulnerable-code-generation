//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c)) {
        return 1;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    i = j = 0;
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    char *sanitized_url = sanitize_url(url);
    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL.\n");
    }
    free(sanitized_url);
    return 0;
}