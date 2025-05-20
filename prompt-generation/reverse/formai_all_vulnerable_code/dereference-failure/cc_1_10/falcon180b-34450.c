//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool is_valid_url_character(char c) {
    return (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~');
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    char *current_pos = sanitized_url;

    if (!url ||!*url) {
        strcpy(sanitized_url, "");
        return sanitized_url;
    }

    while (*url) {
        if (is_valid_url_character(*url)) {
            strncat(sanitized_url, url, 1);
        } else {
            strncat(sanitized_url, "%", 1);
            url++;
            int hex_value = 0;
            int i = 0;

            while (isxdigit(*url)) {
                if (isdigit(*url)) {
                    hex_value = (hex_value * 16) + (*url - '0');
                } else {
                    hex_value = (hex_value * 16) + (*url - 'A' + 10);
                }

                url++;
                i++;

                if (i == 3) {
                    break;
                }
            }

            sprintf(current_pos, "%%%02X", hex_value);
            current_pos += 3;
        }

        url++;
    }

    *current_pos = '\0';
    return sanitized_url;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}