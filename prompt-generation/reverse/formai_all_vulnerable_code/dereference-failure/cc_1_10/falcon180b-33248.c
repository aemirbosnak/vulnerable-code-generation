//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '/' || c == ':' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == '@') {
        return 1;
    } else {
        return 0;
    }
}

void sanitize_url(char* url) {
    int len = strlen(url);
    if (len >= MAX_URL_LEN) {
        // URL is too long
        printf("Error: URL is too long.\n");
        exit(1);
    }

    // Remove leading/trailing spaces
    while (isspace(*url)) {
        url++;
    }
    while (isspace(url[len - 1])) {
        url[--len] = '\0';
    }

    // Encode special characters
    for (int i = 0; i < len; i++) {
        if (!is_valid_url_char(url[i])) {
            sprintf(&url[i], "%%%02X", (int)url[i]);
        }
    }
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}