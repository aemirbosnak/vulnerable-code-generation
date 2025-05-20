//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_scheme(char *scheme) {
    int len = strlen(scheme);
    if (len < 1 || len > 8) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalnum(scheme[i]) && scheme[i]!= '+' && scheme[i]!= '-' && scheme[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

int is_valid_domain(char *domain) {
    int len = strlen(domain);
    if (len < 1 || len > 255) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalnum(domain[i]) && domain[i]!= '.' && domain[i]!= '-') {
            return 0;
        }
    }
    return 1;
}

int is_valid_url(char *url) {
    int len = strlen(url);
    if (len >= MAX_URL_LEN) {
        return 0;
    }
    char *scheme = strtok(url, "://");
    if (scheme == NULL) {
        return 0;
    }
    if (!is_valid_scheme(scheme)) {
        return 0;
    }
    char *domain = strtok(NULL, "/");
    if (domain == NULL) {
        return 0;
    }
    if (!is_valid_domain(domain)) {
        return 0;
    }
    return 1;
}

void sanitize_url(char *url) {
    int len = strlen(url);
    if (len >= MAX_URL_LEN) {
        strncpy(url, "", MAX_URL_LEN);
        return;
    }
    char *scheme = strtok(url, "://");
    if (scheme == NULL) {
        strncpy(url, "", MAX_URL_LEN);
        return;
    }
    if (!is_valid_scheme(scheme)) {
        strncpy(url, "", MAX_URL_LEN);
        return;
    }
    char *domain = strtok(NULL, "/");
    if (domain == NULL) {
        strncpy(url, "", MAX_URL_LEN);
        return;
    }
    if (!is_valid_domain(domain)) {
        strncpy(url, "", MAX_URL_LEN);
        return;
    }
    strncpy(url, "http://", MAX_URL_LEN);
    strncat(url, scheme, MAX_URL_LEN);
    strncat(url, "/", MAX_URL_LEN);
    strncat(url, domain, MAX_URL_LEN);
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}