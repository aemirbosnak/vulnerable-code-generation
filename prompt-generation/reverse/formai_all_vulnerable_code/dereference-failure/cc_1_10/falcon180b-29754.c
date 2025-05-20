//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    return (isalnum(c) || strchr("!#$&'()*+-./:;=?@[\\]^_`{|}~", c)!= NULL);
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

void sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    sanitized_url[0] = '\0';

    for (i = 0, j = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }

    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("Valid URL\n");
        sanitize_url(url);
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}