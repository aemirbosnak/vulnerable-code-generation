//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

/**
 * Sanitizes a URL by removing any non-ASCII characters and
 * converting all uppercase characters to lowercase.
 * @param url The URL to sanitize.
 * @param sanitized_url The sanitized URL.
 * @return 1 if the URL was successfully sanitized, 0 otherwise.
 */
int sanitize_url(const char* url, char* sanitized_url) {
    int len = strlen(url);
    if (len >= MAX_URL_LEN) {
        return 0;
    }

    char* clean_url = malloc(len + 1);
    if (clean_url == NULL) {
        return 0;
    }

    int clean_len = 0;
    for (int i = 0; i < len; i++) {
        if (isascii(url[i])) {
            clean_url[clean_len++] = tolower(url[i]);
        }
    }

    clean_url[clean_len] = '\0';
    strcpy(sanitized_url, clean_url);

    free(clean_url);
    return 1;
}

int main() {
    char url[MAX_URL_LEN];
    char sanitized_url[MAX_URL_LEN];

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    if (sanitize_url(url, sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Error: URL is too long or contains non-ASCII characters.\n");
    }

    return 0;
}