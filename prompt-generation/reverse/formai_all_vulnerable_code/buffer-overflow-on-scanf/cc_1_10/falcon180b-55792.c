//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else if (c == '.') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (i < strlen(url)) {
        if (!is_valid_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void sanitize_url(char *url) {
    int i = 0;
    while (i < strlen(url)) {
        if (url[i] == '%') {
            i++;
            if (i >= strlen(url)) {
                break;
            }
            if (isxdigit(url[i]) && isxdigit(url[i+1]) && isxdigit(url[i+2])) {
                i += 2;
            } else {
                url[i] = '\0';
                break;
            }
        } else if (url[i] == '.' && i == 0) {
            url[i] = '\0';
        } else if (url[i] == '.' && i == strlen(url) - 1) {
            url[i] = '\0';
        } else {
            i++;
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    if (is_valid_url(url)) {
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL.\n");
    }
    return 0;
}