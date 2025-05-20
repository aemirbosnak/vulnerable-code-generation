//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 256

void sanitize(char *input, char *output) {
    int i = 0, j = 0;
    bool is_valid = true;

    while (input[i] != '\0') {
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            input[i] == '.' ||
            input[i] == '-' ||
            input[i] == '_' ||
            input[i] == '~') {
            output[j++] = input[i];
        } else if (input[i] == '?') {
            if (is_valid) {
                output[j++] = '?';
                is_valid = false;
            }
        } else if (input[i] == '#') {
            if (!is_valid) {
                output[j++] = '#';
                i++;
                while (input[i] != '&') {
                    output[j++] = input[i++];
                }
                i++;
                while (input[i] != '\0') {
                    if ((input[i] >= 'A' && input[i] <= 'Z') ||
                        (input[i] >= 'a' && input[i] <= 'z') ||
                        input[i] == '=' ||
                        input[i] == '&') {
                        output[j++] = input[i];
                    }
                    i++;
                }
                is_valid = true;
            }
        } else {
            is_valid = false;
        }
        i++;
    }

    output[j] = '\0';
}

int main() {
    char input[MAX_LEN], output[MAX_LEN];

    printf("Enter a URL to sanitize: ");
    scanf("%s", input);

    sanitize(input, output);

    printf("Sanitized URL: %s\n", output);

    return 0;
}