//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to remove invalid characters and trailing slashes from URL */
void sanitizeURL(char *url) {
    int i, j, len;
    len = strlen(url);
    
    /* check for "http://" or "https://" at the beginning of the URL */
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        printf("Error: Invalid URL\n");
        /* exit program if URL is invalid */
        exit(1);
    }
    
    /* remove trailing slashes if they exist */
    if (url[len-1] == '/') {
        url[len-1] = '\0';
        len--;
    }
    
    /* remove whitespace characters */
    i = j = 0;
    while (url[i]) {
        if (!isspace(url[i])) {
            url[j++] = url[i];
        }
        i++;
    }
    url[j] = '\0';
    
    /* remove invalid characters */
    i = j = 0;
    while (url[i]) {
        /* only allow alphanumeric characters, hyphens, and periods in the URL */
        if (isalnum(url[i]) || url[i] == '-' || url[i] == '.') {
            url[j++] = url[i];
        }
        i++;
    }
    url[j] = '\0';
}

int main() {
    char url[1000];
    printf("Enter a URL: ");
    fgets(url, 1000, stdin);
    /* remove newline character */
    url[strlen(url)-1] = '\0';
    
    sanitizeURL(url);
    
    printf("The sanitized URL is: %s\n", url);
    
    return 0;
}