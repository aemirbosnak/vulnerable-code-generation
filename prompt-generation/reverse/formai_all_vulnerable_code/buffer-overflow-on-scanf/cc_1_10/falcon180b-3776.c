//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

/*
 * Returns true if the given character is a valid URL character.
 */
static int is_valid_url_char(char c) {
    return (isalnum(c) || strchr("-._~:/?#[]@!$&'()*+,;=%", c)!= NULL);
}

/*
 * Returns true if the given string is a valid URL.
 */
static int is_valid_url(const char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

/*
 * Sanitizes the given URL by removing any invalid characters.
 */
static void sanitize_url(char *url, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        if (!is_valid_url_char(url[i])) {
            url[i] = '_';
        }
    }
}

/*
 * Returns a pointer to the sanitized version of the given URL.
 */
char *url_sanitizer(const char *url) {
    int len = strlen(url);
    if (len > MAX_URL_LENGTH) {
        len = MAX_URL_LENGTH;
    }
    char *sanitized_url = malloc(len + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }
    strncpy(sanitized_url, url, len);
    sanitized_url[len] = '\0';
    sanitize_url(sanitized_url, len);
    return sanitized_url;
}

int main() {
    char *input_url, *sanitized_url;

    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    sanitized_url = url_sanitizer(input_url);

    if (sanitized_url == NULL) {
        printf("Error: Failed to sanitize URL.\n");
    } else {
        printf("Sanitized URL: %s\n", sanitized_url);
    }

    free(sanitized_url);

    return 0;
}