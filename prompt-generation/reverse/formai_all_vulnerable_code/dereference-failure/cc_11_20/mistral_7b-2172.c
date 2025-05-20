//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1024

void sanitize_url(char *url) {
    int i, j;
    bool is_valid = true;

    for (i = 0; url[i] && is_valid; i++) {
        if (url[i] >= 'A' && url[i] <= 'Z') {
            // Valid alphabets
        } else if (url[i] >= 'a' && url[i] <= 'z') {
            // Valid lowercase alphabets
        } else if (url[i] >= '0' && url[i] <= '9') {
            // Valid digits
        } else if (url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '~') {
            // Valid special characters
        } else {
            is_valid = false;
            for (j = i; url[j]; j++) {
                if (url[j] != '%' && url[j - 1] != '%') {
                    url[j] = '\0';
                    break;
                }
                i--;
            }
            if (!is_valid && url[i - 1] != '%') {
                // Invalid character, print error and exit
                printf("Invalid URL: '%c' is not allowed.\n", url[i]);
                exit(EXIT_FAILURE);
            }
        }
    }

    // Replace '%' with the corresponding hexadecimal character
    for (i = 0; url[i]; i++) {
        if (url[i] == '%') {
            if (url[i + 1] && (url[i + 1] >= '0' && url[i + 1] <= '9') &&
                url[i + 2] && (url[i + 2] >= '0' && url[i + 2] <= '9')) {
                url[i] = (url[i + 1] << 4) + (url[i + 2] - '0');
                i++;
            } else {
                printf("Invalid URL: '%%c%c' is not a valid hexadecimal character.\n", url[i], url[i + 1]);
                exit(EXIT_FAILURE);
            }
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return EXIT_SUCCESS;
}