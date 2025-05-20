//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize input URL
void sanitize_url(char *url) {
    int i, j;
    char *p;

    // Remove leading and trailing whitespace
    url[0] = toupper(url[0]);
    j = strlen(url) - 1;
    url[j] = toupper(url[j]);
    p = url;
    while (isspace(*p)) {
        p++;
    }
    while (isspace(url[j])) {
        url[j] = '\0';
        j--;
    }

    // Remove invalid characters
    for (i = 0; i < j; i++) {
        if (!isalnum(url[i]) && (url[i]!= '.' && url[i]!= '-' && url[i]!= '_' && url[i]!= '~')) {
            url[i] = '_';
        }
    }

    // Remove consecutive dots
    p = url;
    while (*p) {
        if (*p == '.') {
            if (p > url && p[-1] == '.') {
                strcpy(p, p + 1);
            }
        }
        p++;
    }

    // Add missing protocol (http:// or https://)
    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8)) {
        strcat(url, "http://");
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get user input URL
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize URL
    sanitize_url(url);

    // Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}