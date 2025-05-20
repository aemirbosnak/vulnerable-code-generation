//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalpha(c) || isdigit(c) || strchr("!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?", c)!= NULL) {
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

char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    j = 0;
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char *input_url;
    char *sanitized_url;

    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    sanitized_url = sanitize_url(input_url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}