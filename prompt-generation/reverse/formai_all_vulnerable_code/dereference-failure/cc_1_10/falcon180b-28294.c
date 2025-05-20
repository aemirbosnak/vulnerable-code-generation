//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int sanitized_url_length = 0;
    int i = 0;
    char c;

    // Remove leading and trailing white spaces
    while (isspace(url[i])) {
        i++;
    }
    while (isspace(url[strlen(url) - i - 1])) {
        i--;
    }

    // Replace non-ASCII characters with their ASCII equivalents
    while ((c = url[i])!= '\0') {
        if (c < 32 || c > 126) {
            sanitized_url[sanitized_url_length++] = '%';
            sanitized_url[sanitized_url_length++] = '2';
            sanitized_url[sanitized_url_length++] = '0';
            sanitized_url[sanitized_url_length++] = (c / 16) + '0';
            sanitized_url[sanitized_url_length++] = (c % 16) + '0';
        } else {
            sanitized_url[sanitized_url_length++] = c;
        }
        i++;
    }
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char input_url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", input_url);

    char *sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}