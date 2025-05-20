//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize URL by removing invalid characters and encoding reserved characters
void sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    char *p = sanitized_url;
    int len = strlen(url);

    // Copy valid characters to sanitized URL
    for (int i = 0; i < len; i++) {
        if (isalnum(url[i]) || url[i] == '-' || url[i] == '.' || url[i] == '_' || url[i] == '~' || url[i] == '!' || url[i] == '$' || url[i] == '&' || url[i] == '\'' || url[i] == '(' || url[i] == ')' || url[i] == '*' || url[i] == '+' || url[i] == ',') {
            *p = url[i];
            p++;
        }
    }

    // Encode reserved characters
    *p = 0;
    p = sanitized_url;
    while (*p) {
        if (*p == '%') {
            *(p + 1) = '2';
            *(p + 2) = '5';
            p += 2;
        }
        p++;
    }

    // Copy sanitized URL back to original buffer
    strcpy(url, sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get URL from user input
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize URL
    sanitize_url(url);

    // Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}