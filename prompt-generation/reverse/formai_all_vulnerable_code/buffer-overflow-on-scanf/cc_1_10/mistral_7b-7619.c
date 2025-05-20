//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 256

bool is_alnum(char c) {
    return (isalpha(c) || isdigit(c) || c == '_' || c == '-');
}

bool is_hseparator(char c) {
    return (c == ':' || c == '/' || c == '?');
}

bool is_valid_char(char c) {
    return is_alnum(c) || is_hseparator(c) || c == '.' || c == '_' || c == '-';
}

bool is_valid_host(char *host) {
    int len = strlen(host);
    if (len > MAX_LENGTH) return false;
    for (int i = 0; i < len; i++) {
        if (!is_valid_char(host[i])) {
            return false;
        }
    }
    return true;
}

void sanitize_url(char *url) {
    int len = strlen(url);
    int i = 0, j = 0;

    while (i < len) {
        if (url[i] == '%' && i < len - 2) {
            unsigned char u, h;
            sscanf(&url[i], "%2hhx%2hhx", &h, &u);
            url[j++] = (char)u;
            i += 2;
        } else if (is_valid_char(url[i])) {
            url[j++] = url[i];
            i++;
        } else {
            i++;
        }
    }

    url[j] = '\0';
}

int main() {
    char url[MAX_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}