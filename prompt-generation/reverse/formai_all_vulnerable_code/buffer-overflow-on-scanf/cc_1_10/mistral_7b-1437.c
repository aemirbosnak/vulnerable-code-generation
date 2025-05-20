//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1024

void sanitize(char *url) {
    int i, j;
    char clean_url[MAX_LENGTH];

    i = j = 0;

    while (url[i] != '\0') {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/') {
            clean_url[j++] = url[i];
        }

        if ((url[i] == '?' || url[i] == '&') && i < MAX_LENGTH - 2) {
            clean_url[j++] = '_';
            i++;

            while (url[i] != '=' && i < MAX_LENGTH) {
                if (isalnum(url[i])) {
                    clean_url[j++] = url[i];
                }
                i++;
            }

            if (url[i] == '=') {
                i++;
            }
        }

        i++;
    }

    clean_url[j] = '\0';
    strcpy(url, clean_url);
}

int main() {
    char url[MAX_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}