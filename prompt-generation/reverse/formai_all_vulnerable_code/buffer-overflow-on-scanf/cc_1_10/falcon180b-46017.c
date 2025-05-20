//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || strchr("!#$&'()*+,-./:;=?@[\\]^_`{|}~", c)!= NULL) {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void sanitize_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            url[i] = '%';
            i++;
        }
        i++;
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    if (!is_valid_url(url)) {
        printf("Invalid URL!\n");
        return 1;
    }

    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}