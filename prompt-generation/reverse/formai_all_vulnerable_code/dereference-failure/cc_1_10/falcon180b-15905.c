//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the URL
void sanitize_url(char *url) {
    int i, j;
    char *clean_url = malloc(MAX_URL_LENGTH * sizeof(char));
    clean_url[0] = '\0';

    // Remove any leading or trailing spaces
    while (isspace(*url)) {
        url++;
    }
    while (isspace(*(url + strlen(url) - 1))) {
        url[strlen(url) - 1] = '\0';
    }

    // Remove any special characters
    for (i = 0; url[i]!= '\0'; i++) {
        if (!isalnum(url[i]) && url[i]!= '-') {
            url[i] = '_';
        }
    }

    // Convert the URL to lowercase
    for (i = 0; url[i]!= '\0'; i++) {
        if (isalpha(url[i])) {
            url[i] = tolower(url[i]);
        }
    }

    // Remove any consecutive underscores
    j = 0;
    for (i = 0; url[i]!= '\0'; i++) {
        if (url[i]!= '_') {
            clean_url[j++] = url[i];
        }
    }
    clean_url[j] = '\0';

    // Copy the sanitized URL to the original URL
    strcpy(url, clean_url);
    free(clean_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}