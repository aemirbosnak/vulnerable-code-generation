//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void sanitize_url(char *url) {
    int i, j;
    char *ptr;
    char *scheme = "http://";
    char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;=";

    // Check if the URL is already sanitized
    if (strncmp(url, scheme, strlen(scheme))!= 0) {
        strcat(url, scheme);
    }

    // Convert the URL to lowercase
    for (i = 0; url[i]!= '\0'; i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any non-allowed characters
    for (i = 0, ptr = url; i < strlen(url); i++) {
        if (strchr(allowed_chars, url[i]) == NULL) {
            memmove(ptr, ptr + 1, strlen(ptr) - i);
            i--;
        } else {
            ptr++;
        }
    }

    // Remove any trailing slashes
    while (ptr > url && ptr[-1] == '/') {
        ptr--;
    }

    // Add a trailing slash if necessary
    if (ptr == url + strlen(url) - 1) {
        strcat(url, "/");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}