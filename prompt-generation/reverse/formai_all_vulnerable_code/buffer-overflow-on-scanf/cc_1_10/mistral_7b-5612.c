//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1024

bool is_alnum(char c) {
    return (isalpha(c) || isdigit(c) || c == '_' || c == '-');
}

void sanitize_url(char *url) {
    int length = strlen(url);
    int index = 0;

    // Welcome message
    printf("\nHi there, sunshine!\n");
    printf("Let's make your URL all shiny and safe!\n");

    // Iterate through the URL and sanitize it
    for (int i = 0; i < length; i++) {
        if (url[i] == ' ') {
            url[i] = '_';
            printf("Replaced space with underscore at position %d\n", i);
        }

        if (!is_alnum(url[i]) && url[i] != ':' && url[i] != '/' && url[i] != '?' && url[i] != '&' && url[i] != '#' && url[i] != '=' && url[i] != '.' && url[i] != '-' && url[i] != '_') {
            url[i] = '_';
            printf("Replaced invalid character '%c' with underscore at position %d\n", url[i], i);
        }

        if (i > 0 && (url[i] == ':' || url[i] == '/')) {
            if (url[i-1] != '/') {
                url[i-1] = '/';
                printf("Added missing forward slash before '%c' at position %d\n", url[i], i-1);
            }
        }

        if (i < length-1 && (url[i] == '/' || url[i] == '?') && is_alnum(url[i+1])) {
            url[i+1] = '_';
            printf("Replaced invalid first character after '%c' with underscore at position %d\n", url[i], i+1);
        }

        index++;
    }

    url[index] = '\0';

    // Print the sanitized URL to the user
    printf("\nYour sanitized URL is: %s\n", url);
}

int main() {
    char url[MAX_LENGTH];

    printf("Enter your cheerful URL: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}