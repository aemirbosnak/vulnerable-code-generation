//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url) {
    int i, j, len = strlen(url);
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    memset(sanitized_url, 0, MAX_URL_LENGTH);

    // remove leading and trailing whitespace
    while (isspace(url[0])) {
        url++;
        len--;
    }
    while (isspace(url[len-1])) {
        len--;
    }

    // remove any non-alphanumeric characters
    for (i = 0, j = 0; i < len; i++) {
        if (isalnum(url[i])) {
            sanitized_url[j++] = tolower(url[i]);
        }
    }

    // replace multiple dots with a single dot
    for (i = 0, j = 0; i < strlen(sanitized_url); i++) {
        if (sanitized_url[i] == '.') {
            if (i > 0 && sanitized_url[i-1] == '.') {
                continue;
            }
        }
        sanitized_url[j++] = sanitized_url[i];
    }

    // remove trailing dot
    if (sanitized_url[strlen(sanitized_url)-1] == '.') {
        sanitized_url[strlen(sanitized_url)-1] = '\0';
    }

    return sanitized_url;
}

int main() {
    char *input_url;
    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    char *sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}