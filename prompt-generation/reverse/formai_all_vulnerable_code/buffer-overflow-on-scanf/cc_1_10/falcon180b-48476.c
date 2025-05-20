//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || strchr("-.+*'()", c)!= NULL) {
        return 1;
    }
    return 0;
}

void sanitize_url(char *url) {
    int i, j;
    char *start;
    int len = strlen(url);
    char *sanitized_url = malloc(MAX_URL_LEN);
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    i = 0;
    start = url;
    while (i < len) {
        if (is_valid_url_char(*start)) {
            sanitized_url[i] = *start;
            i++;
            start++;
        } else if (i > 0 && sanitized_url[i - 1] == '%') {
            char hex[3];
            sprintf(hex, "%02X", (unsigned char)*start);
            sanitized_url[i] = '%';
            i++;
            start++;
            sanitized_url[i] = hex[0];
            i++;
            start++;
            sanitized_url[i] = hex[1];
            i++;
        } else {
            start++;
        }
    }
    sanitized_url[i] = '\0';
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    return 0;
}