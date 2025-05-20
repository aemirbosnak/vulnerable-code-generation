//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define MAX_SANITIZED_SIZE 2048

bool is_valid_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '-') || (c == '.') || (c == '_') || (c == '~') || (c == '!') || (c == '$') || (c == '&') || (c == '*') || (c == '+') || (c == ',') || (c == ';') || (c == '=');
}

char* sanitize_url(char* input) {
    char* sanitized = malloc(MAX_SANITIZED_SIZE);
    char* output = sanitized;
    int input_len = strlen(input);
    int output_len = 0;

    for (int i = 0; i < input_len; i++) {
        char c = input[i];

        if (is_valid_char(c)) {
            *output++ = c;
            output_len++;
        } else if (c == '%') {
            if (i + 2 < input_len && isxdigit(input[i + 1]) && isxdigit(input[i + 2])) {
                char hex1 = input[i + 1];
                char hex2 = input[i + 2];
                char dec = (hex1 - '0') * 16 + (hex2 - '0');
                if (is_valid_char(dec)) {
                    *output++ = dec;
                    output_len++;
                    i += 2;
                }
            }
        }
    }

    *output = '\0';
    return sanitized;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter a URL to sanitize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    char* sanitized = sanitize_url(input);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}