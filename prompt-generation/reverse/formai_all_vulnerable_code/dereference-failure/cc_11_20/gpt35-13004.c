//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

char *sanitize_url(char *url) {
    char *new_url = (char *) malloc(MAX_URL_LENGTH * sizeof(char));
    char *temp;
    int i, j;

    // Removing whitespace from the beginning and end of the URL
    while (*url == ' ' || *url == '\t') {
        url++;
    }
    i = strlen(url) - 1;
    while (i >= 0 && (url[i] == ' ' || url[i] == '\t')) {
        url[i] = '\0';
        i--;
    }

    // Copying the sanitized URL to the new string
    temp = new_url;
    i = 0;
    while (*url != '\0') {
        if ((*url >= 'a' && *url <= 'z') ||
            (*url >= 'A' && *url <= 'Z') ||
            (*url >= '0' && *url <= '9') ||
            (*url == '.') || (*url == '/') ||
            (*url == ':') || (*url == '?') ||
            (*url == '=') || (*url == '&') ||
            (*url == '-')) {
            temp[i] = *url;
            url++;
            i++;
        } else if (*url == ' ') {
            // Replacing spaces with '+' symbol in the URL
            temp[i] = '+';
            url++;
            i++;
        } else {
            // Ignoring other characters in the URL
            url++;
        }
    }
    temp[i] = '\0';

    return new_url;
}

int main() {
    char url[MAX_URL_LENGTH];

    // Reading a URL from the user
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';

    // Sanitizing the URL and printing the result
    char *new_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", new_url);

    free(new_url);

    return 0;
}