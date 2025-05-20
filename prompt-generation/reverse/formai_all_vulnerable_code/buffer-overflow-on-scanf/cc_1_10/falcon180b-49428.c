//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SANITIZED_LENGTH 2000

int is_valid_url_character(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char* url) {
    int length = strlen(url);
    if (length > MAX_INPUT_LENGTH) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char* input_url, char* sanitized_url) {
    int input_length = strlen(input_url);
    int sanitized_length = 0;
    for (int i = 0; i < input_length; i++) {
        if (is_valid_url_character(input_url[i])) {
            sanitized_url[sanitized_length++] = input_url[i];
        }
    }
    sanitized_url[sanitized_length] = '\0';
}

int main() {
    char input_url[MAX_INPUT_LENGTH];
    char sanitized_url[MAX_SANITIZED_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);
    sanitize_url(input_url, sanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    return 0;
}