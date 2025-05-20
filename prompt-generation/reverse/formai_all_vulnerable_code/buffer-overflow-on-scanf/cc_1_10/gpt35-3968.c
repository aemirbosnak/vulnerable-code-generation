//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000 // Maximum length of URL that can be sanitized
#define MAX_DOMAIN_LENGTH 100 // Maximum length of a domain name

// Function to remove protocol (http or https) from URL
void removeProtocol(char *url) {
    if(strstr(url, "http://") != NULL) {
        memmove(url, url + strlen("http://"), strlen(url + strlen("http://")) + 1);
    } else if (strstr(url, "https://") != NULL) {
        memmove(url, url + strlen("https://"), strlen(url + strlen("https://")) + 1);
    }
}

// Function to remove trailing slashes from URL
void removeTrailingSlashes(char *url) {
    int urlLength = strlen(url);
    while(urlLength > 0 && url[urlLength - 1] == '/') {
        urlLength--;
    }
    url[urlLength] = '\0';
}

// Function to remove www prefix from domain name
void removeWWW(char *domain) {
    if(strstr(domain, "www.") == domain) {
        memmove(domain, domain + strlen("www."), strlen(domain + strlen("www.")) + 1);
    }
}

// Function to sanitize a given URL
void sanitizeUrl(char *url) {
    removeProtocol(url); // Removing http or https from URL
    removeTrailingSlashes(url); // Removing trailing slashes from URL
    char *domain = strchr(url, '/');
    if(domain != NULL) {
        domain++; // Pointing to the domain name (ex: google.com)
        removeWWW(domain); // Removing www prefix from domain name
    }
}

// Function to print sanitized URL
void printSanitizedUrl(char *url) {
    printf("Sanitized URL: %s\n", url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitizeUrl(url);
    printSanitizedUrl(url);
    return 0;
}