//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048 // Maximum length of input URL
#define MAX_SCHEME_LENGTH 10 // Maximum length of URL scheme (e.g. "http://")
#define MAX_DOMAIN_LENGTH 255 // Maximum length of domain name (e.g. "example.com")
#define MAX_PATH_LENGTH 1024 // Maximum length of URL path (e.g. "/page/index.html")
#define MAX_QUERY_LENGTH 1024 // Maximum length of URL query string (e.g. "?param=value")

/* Function to sanitize the input URL */
void sanitize_url(char *url) {
    char scheme[MAX_SCHEME_LENGTH+1] = ""; // URL scheme
    char domain[MAX_DOMAIN_LENGTH+1] = ""; // Domain name
    char path[MAX_PATH_LENGTH+1] = ""; // URL path
    char query[MAX_QUERY_LENGTH+1] = ""; // URL query string
    int i, j;

    // Find the scheme (e.g. "http://")
    for (i = 0; i < MAX_SCHEME_LENGTH && url[i] != ':' && url[i] != '\0'; i++) {
        scheme[i] = url[i];
    }
    scheme[i++] = ':';
    scheme[i] = '\0';
    if (strcasecmp(scheme, "http:") != 0 && strcasecmp(scheme, "https:") != 0) {
        printf("Invalid URL scheme: %s\n", scheme);
        return;
    }

    // Find the domain name (e.g. "example.com")
    if (url[i] == '/' && url[i+1] == '/') {
        i += 2;
        for (j = 0; j < MAX_DOMAIN_LENGTH && url[i+j] != '/' && url[i+j] != '\0'; j++) {
            domain[j] = url[i+j];
        }
        domain[j] = '\0';
        i += j;
    }
    if (strspn(domain, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.") < strlen(domain)) {
        printf("Invalid domain name: %s\n", domain);
        return;
    }

    // Find the URL path (e.g. "/page/index.html")
    for (j = 0; j < MAX_PATH_LENGTH && url[i+j] != '\0' && url[i+j] != '?'; j++) {
        path[j] = url[i+j];
    }
    path[j] = '\0';

    // Find the URL query string (e.g. "?param=value")
    if (url[i+j] == '?') {
        for (i += j, j = 0; j < MAX_QUERY_LENGTH && url[i+j] != '\0'; j++) {
            query[j] = url[i+j];
        }
        query[j] = '\0';
    }

    // Print the sanitized URL
    printf("Sanitized URL:\n");
    printf("%s//%s%s%s\n", scheme, domain, path, query);
}

/* Main function */
int main() {
    char url[MAX_URL_LENGTH];

    // Get the input URL
    printf("Enter URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';

    // Sanitize the URL
    sanitize_url(url);

    return 0;
}