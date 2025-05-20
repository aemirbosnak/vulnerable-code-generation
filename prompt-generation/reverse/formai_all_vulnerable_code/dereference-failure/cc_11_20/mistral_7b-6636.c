//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size_t url_length = strlen(argv[1]);
    if (url_length > MAX_URL_LENGTH) {
        printf("URL too long.\n");
        exit(EXIT_FAILURE);
    }

    char sanitized_url[MAX_URL_LENGTH];
    bool is_valid = true;

    int i = 0;
    for (; i < url_length; ++i) {
        if ((argv[1][i] < 'A' || argv[1][i] > 'Z') &&
            (argv[1][i] < 'a' || argv[1][i] > 'z') &&
            (argv[1][i] < '0' || argv[1][i] > '9') &&
            argv[1][i] != '.' && argv[1][i] != '-' &&
            argv[1][i] != '_' && argv[1][i] != '~') {
            is_valid = false;
            break;
        }

        if (i > 0 && argv[1][i] == ':') {
            if (argv[1][i-1] != '/') {
                is_valid = false;
                break;
            }
        }

        sanitized_url[i] = argv[1][i];
    }

    sanitized_url[i] = '\0';

    if (!is_valid) {
        printf("Invalid URL.\n");
        exit(EXIT_FAILURE);
    }

    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}