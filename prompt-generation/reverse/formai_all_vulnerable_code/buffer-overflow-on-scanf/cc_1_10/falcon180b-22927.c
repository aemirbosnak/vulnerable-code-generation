//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is a valid URL character
bool is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    } else if (c >= 'A' && c <= 'Z') {
        return true;
    } else if (c >= '0' && c <= '9') {
        return true;
    } else if (c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' || c == '[') {
        return true;
    } else if (c == ']' || c == '^' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~') {
        return true;
    } else {
        return false;
    }
}

// Function to sanitize a URL
void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    while (i < strlen(url)) {
        if (is_valid_url_char(url[i])) {
            url[j] = url[i];
            j++;
        }
        i++;
    }
    url[j] = '\0';
}

// Function to print the sanitized URL
void print_sanitized_url(char* url) {
    printf("Sanitized URL: %s\n", url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    print_sanitized_url(url);
    return 0;
}