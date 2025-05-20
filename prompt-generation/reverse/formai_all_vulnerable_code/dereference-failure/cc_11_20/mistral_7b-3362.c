//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 256

void sanitize_url(char *url) {
    int i, j;
    bool is_valid = true;

    for (i = 0; url[i] != '\0' && i < MAX_LEN; i++) {
        if (url[i] < 'A' || url[i] > 'Z' && url[i] < 'a' || url[i] > 'z') {
            if (url[i] != '.' && url[i] != '-' && url[i] != '_' && url[i] != '~') {
                if (i > 0 && (url[i-1] == '.' || url[i-1] == '/')) {
                    url[i] = '\0';
                    i--;
                    continue;
                }
                is_valid = false;
                break;
            }
        }
    }

    if (!is_valid) {
        printf("Invalid URL: %s\n", url);
        exit(EXIT_FAILURE);
    }

    for (i = 0, j = 0; url[i] != '\0' && i < MAX_LEN; i++) {
        if (url[i] == '%' && i < MAX_LEN - 2) {
            if (url[i+1] && url[i+1] >= '0' && url[i+1] <= '9') {
                if (url[i+2] && (url[i+2] >= '0' && url[i+2] <= '9') ||
                   (url[i+2] >= 'A' && url[i+2] <= 'F') ||
                   (url[i+2] >= 'a' && url[i+2] <= 'f')) {
                    i += 2;
                } else {
                    printf("Invalid URL: %s\n", url);
                    exit(EXIT_FAILURE);
                }
            }
        } else {
            if (j < i) {
                url[j++] = url[i];
            }
        }
    }

    url[j] = '\0';

    printf("Sanitized URL: %s\n", url);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sanitize_url(argv[1]);

    return EXIT_SUCCESS;
}