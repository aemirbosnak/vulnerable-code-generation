//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <regex.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    regex_t regex;
    int ret;
    ret = regcomp(&regex, "^https?://[a-z0-9.-]+\\.[a-z]{2,}$", REG_EXTENDED);
    if (ret!= 0) {
        return 0;
    }
    ret = regexec(&regex, url, 0, NULL, 0);
    regfree(&regex);
    return ret == 0;
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    char *p = sanitized_url;
    int i = 0;
    int j = 0;
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char *sanitized_url = sanitize_url(url);
    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }
    free(sanitized_url);
    return 0;
}