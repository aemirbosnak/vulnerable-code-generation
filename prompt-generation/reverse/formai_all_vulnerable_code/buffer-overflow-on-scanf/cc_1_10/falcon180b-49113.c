//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SANITIZED_URL_LENGTH 2048

int is_valid_url_character(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '-') || (c == '.') || (c == '_') || (c == '~');
}

int sanitize_url(char* input_url, char* output_url) {
    int input_url_length = strlen(input_url);
    int output_url_length = 0;
    char* input_url_pointer = input_url;
    char* output_url_pointer = output_url;

    while (input_url_pointer - input_url < input_url_length) {
        char c = *input_url_pointer;

        if (is_valid_url_character(c)) {
            *output_url_pointer = c;
            output_url_pointer++;
            output_url_length++;
        } else if (c == '%') {
            if (isxdigit(*(input_url_pointer + 1)) && isxdigit(*(input_url_pointer + 2))) {
                *output_url_pointer = *input_url_pointer;
                output_url_pointer++;
                output_url_length++;

                input_url_pointer += 3;
            } else {
                return 0;
            }
        } else {
            return 0;
        }

        input_url_pointer++;
    }

    *output_url_pointer = '\0';
    return 1;
}

int main() {
    char input_url[MAX_SANITIZED_URL_LENGTH];
    char sanitized_url[MAX_SANITIZED_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    sanitize_url(input_url, sanitized_url);

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}