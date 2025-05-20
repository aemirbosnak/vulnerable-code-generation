//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

int is_valid_char(char c) {
    if (isalnum(c)) {
        return 1;
    }
    switch(c) {
        case '.':
        case '-':
        case '_':
        case '~':
        case '!':
        case '$':
        case '&':
        case '*':
        case '+':
        case ',':
        case ';':
        case '=':
        case '?':
        case '@':
            return 1;
        default:
            return 0;
    }
}

void sanitize_url(char* url) {
    int i = 0;
    char* new_url = malloc(MAX_LENGTH * sizeof(char));
    while(url[i]!= '\0') {
        if(is_valid_char(url[i])) {
            new_url[i] = url[i];
            i++;
        } else {
            new_url[i] = '%';
            i++;
            sprintf(&new_url[i], "%02X", url[i]);
            i += 2;
        }
    }
    new_url[i] = '\0';
    strcpy(url, new_url);
    free(new_url);
}

int main() {
    char url[MAX_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}