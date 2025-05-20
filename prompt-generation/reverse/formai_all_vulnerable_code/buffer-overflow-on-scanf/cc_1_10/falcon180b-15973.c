//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    return (isalnum(c) || strchr("!@#$%^&*()_+-=[]{};:,.<>/? ", c)!= NULL);
}

void sanitize_url(char* url) {
    int len = strlen(url);
    if (len >= MAX_URL_LENGTH) {
        printf("Error: URL too long.\n");
        exit(1);
    }

    int i = 0;
    while (i < len) {
        if (!is_valid_url_character(url[i])) {
            printf("Error: Invalid character in URL.\n");
            exit(1);
        }
        i++;
    }

    char* new_url = malloc(MAX_URL_LENGTH);
    if (new_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    int j = 0;
    while (i < len) {
        if (is_valid_url_character(url[i])) {
            new_url[j] = tolower(url[i]);
            j++;
        }
        i++;
    }

    new_url[j] = '\0';
    strcpy(url, new_url);
    free(new_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}