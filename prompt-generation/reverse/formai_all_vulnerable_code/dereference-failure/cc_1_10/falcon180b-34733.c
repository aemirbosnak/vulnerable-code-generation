//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 1024

char* sanitize_url(char* url) {
    int i, j, len;
    char* new_url = malloc(MAX_LEN);
    char* p;
    len = strlen(url);

    // Convert to lowercase
    for (i = 0; i < len; i++) {
        if (isalpha(url[i])) {
            url[i] = tolower(url[i]);
        }
    }

    // Remove leading and trailing spaces
    while (isspace(url[0])) {
        url++;
    }
    while (isspace(url[len - 1])) {
        url[--len] = '\0';
    }

    // Remove spaces and special characters
    j = 0;
    for (i = 0; i < len; i++) {
        if (isalnum(url[i]) || url[i] == '-') {
            new_url[j++] = url[i];
        }
    }
    new_url[j] = '\0';

    // Add leading slash if necessary
    if (new_url[0]!= '/') {
        new_url = realloc(new_url, strlen("/") + strlen(new_url) + 1);
        strcpy(new_url, "/");
        strcat(new_url, new_url);
    }

    return new_url;
}

int main() {
    char* url = " https://example.com/path/to/page?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}