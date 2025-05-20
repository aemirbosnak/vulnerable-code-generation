//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strcpy(url, argv[1]);

    // Remove leading and trailing whitespaces
    for (int i = 0; url[i] != '\0'; i++) {
        if (isspace(url[i])) {
            url[i] = '\0';
            for (int j = i; url[j] != '\0'; j++) {
                url[j] = url[j + 1];
            }
            i--;
        }
    }

    // Sanitize URL
    int length = strlen(url);
    for (int i = 0; i < length; i++) {
        switch (url[i]) {
            case '?':
            case '/':
            case '&':
            case '=':
                url[i] = '_';
                break;
            case '<':
            case '>':
            case ';':
            case ':':
            case '\\':
            case '|':
            case '`':
            case '~':
                url[i] = '\0';
                for (int j = i; url[j] != '\0'; j++) {
                    url[j] = url[j + 1];
                }
                i--;
                length -= 1;
                break;
            default:
                break;
        }
    }

    printf("Sanitized URL: %s\n", url);
    return 0;
}