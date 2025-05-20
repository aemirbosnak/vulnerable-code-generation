//Code Llama-13B DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_URL_LEN 256

void url_sanitize(char *url) {
    int i, j;
    char *p;

    // Remove any leading and trailing whitespace
    p = url;
    while (*p == ' ' || *p == '\t' || *p == '\n') {
        p++;
    }
    for (i = 0; *p != '\0'; i++) {
        url[i] = *p++;
    }
    url[i] = '\0';

    // Remove any invalid characters
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == ' ' || url[i] == '\t' || url[i] == '\n' || url[i] == '/' || url[i] == '\\') {
            url[i] = '_';
        }
    }

    // Remove any duplicate '_' characters
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == '_') {
            for (j = i + 1; url[j] != '\0'; j++) {
                if (url[j] == '_') {
                    memmove(&url[j], &url[j + 1], strlen(&url[j + 1]) + 1);
                }
            }
        }
    }

    // Remove any leading or trailing '_' characters
    if (url[0] == '_') {
        memmove(&url[0], &url[1], strlen(&url[1]) + 1);
    }
    if (url[strlen(url) - 1] == '_') {
        url[strlen(url) - 1] = '\0';
    }
}

int main() {
    char url[MAX_URL_LEN];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LEN, stdin);
    url_sanitize(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}