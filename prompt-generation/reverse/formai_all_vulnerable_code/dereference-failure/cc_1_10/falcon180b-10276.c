//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 4096

int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-') {
        return 1;
    } else if (c == '.') {
        return 1;
    } else if (c == '_') {
        return 1;
    } else if (c == '~') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    int url_length = strlen(url);

    if (url_length > MAX_URL_LENGTH) {
        printf("error: url is too long.\n");
        return 1;
    }

    if (!is_valid_url(url)) {
        printf("error: invalid url.\n");
        return 1;
    }

    printf("url: %s\n", url);
    return 0;
}