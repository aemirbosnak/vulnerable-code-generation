//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool is_valid_url_character(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return true;
    } else if (ch >= 'a' && ch <= 'z') {
        return true;
    } else if (ch >= '0' && ch <= '9') {
        return true;
    } else if (ch == '-' || ch == '_' || ch == '.' || ch == '~') {
        return true;
    } else {
        return false;
    }
}

bool is_valid_url(char* url) {
    int i = 0;
    while (i < strlen(url)) {
        if (!is_valid_url_character(url[i])) {
            return false;
        }
        i++;
    }
    return true;
}

char* sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    while (i < strlen(url)) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            sprintf(&sanitized_url[i], "%02X", (unsigned char)url[i]);
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char input_url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);
    char* sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}