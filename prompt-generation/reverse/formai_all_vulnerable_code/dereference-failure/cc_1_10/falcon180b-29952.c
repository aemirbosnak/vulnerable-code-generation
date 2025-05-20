//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2048
#define MAX_DOMAIN_LENGTH 256

// Function to check if a character is a valid URL character
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == '$') {
        return 1;
    }
    return 0;
}

// Function to check if a string is a valid domain name
int is_valid_domain_name(char *domain) {
    int len = strlen(domain);
    if (len > MAX_DOMAIN_LENGTH) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalnum(domain[i]) && domain[i]!= '-' && domain[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
    int len = strlen(url);
    char *sanitized_url = malloc(len + 1);
    int sanitized_len = 0;
    for (int i = 0; i < len; i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[sanitized_len++] = url[i];
        }
    }
    sanitized_url[sanitized_len] = '\0';
    return sanitized_url;
}

// Function to sanitize a domain name
char *sanitize_domain_name(char *domain) {
    int len = strlen(domain);
    char *sanitized_domain = malloc(len + 1);
    int sanitized_len = 0;
    for (int i = 0; i < len; i++) {
        if (is_valid_domain_name(domain)) {
            sanitized_domain[sanitized_len++] = domain[i];
        }
    }
    sanitized_domain[sanitized_len] = '\0';
    return sanitized_domain;
}

int main() {
    char url[MAX_URL_LENGTH];
    char domain[MAX_DOMAIN_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    printf("Enter the domain name: ");
    scanf("%s", domain);
    char *sanitized_url = sanitize_url(url);
    char *sanitized_domain = sanitize_domain_name(domain);
    printf("Sanitized URL: %s\n", sanitized_url);
    printf("Sanitized domain name: %s\n", sanitized_domain);
    free(sanitized_url);
    free(sanitized_domain);
    return 0;
}