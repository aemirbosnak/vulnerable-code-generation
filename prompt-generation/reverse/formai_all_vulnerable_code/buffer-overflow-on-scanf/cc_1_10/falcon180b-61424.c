//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else if (c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i, j;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url) {
    int i, j;
    char *new_url = malloc(MAX_URL_LENGTH * sizeof(char));
    memset(new_url, 0, MAX_URL_LENGTH);
    j = 0;
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            new_url[j] = url[i];
            j++;
        }
    }
    new_url[j] = '\0';
    strcpy(url, new_url);
    free(new_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}