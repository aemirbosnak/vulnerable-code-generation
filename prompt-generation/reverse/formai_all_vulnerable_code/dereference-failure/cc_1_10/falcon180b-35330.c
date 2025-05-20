//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 4096

int is_valid_url_character(char c) {
    if (isalnum(c)) {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    int url_length = strlen(url);

    if (url_length > MAX_LENGTH) {
        printf("Error: URL is too long (maximum length is %d characters)\n", MAX_LENGTH);
        return 1;
    }

    if (!is_valid_url(url)) {
        printf("Error: Invalid URL\n");
        return 1;
    }

    printf("Valid URL: %s\n", url);
    return 0;
}