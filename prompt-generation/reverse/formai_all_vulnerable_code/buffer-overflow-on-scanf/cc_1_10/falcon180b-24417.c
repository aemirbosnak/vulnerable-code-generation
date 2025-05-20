//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/') {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void sanitize_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            url[i] = '_';
        }
        i++;
    }
}

void generate_url(int length) {
    char url[MAX_LENGTH];
    int i = 0;
    while (i < length) {
        char c = rand() % 26 + 'a';
        if (is_valid_url_char(c)) {
            url[i] = c;
            i++;
        }
    }
    url[i] = '\0';
    printf("Generated URL: %s\n", url);
}

int main() {
    int length;
    printf("Enter the length of the URL: ");
    scanf("%d", &length);
    if (length > MAX_LENGTH) {
        printf("Error: Length of URL cannot exceed %d characters.\n", MAX_LENGTH);
        return 1;
    }
    char url[MAX_LENGTH];
    printf("Enter the URL: ");
    scanf("%s", url);
    if (!is_valid_url(url)) {
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    }
    generate_url(length);
    return 0;
}