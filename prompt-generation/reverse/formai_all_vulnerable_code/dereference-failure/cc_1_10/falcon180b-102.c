//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 1024

/*
 * Function to sanitize a URL.
 *
 * @param url The URL to sanitize.
 * @param sanitized_url The sanitized URL.
 * @return 1 on success, 0 on failure.
 */
int sanitize_url(const char *url, char *sanitized_url) {
    char *ptr;
    int len = 0;

    /* Remove the protocol if present */
    if (strncasecmp(url, "http://", 7) == 0) {
        len = 7;
    } else if (strncasecmp(url, "https://", 8) == 0) {
        len = 8;
    } else if (strncasecmp(url, "ftp://", 6) == 0) {
        len = 6;
    } else {
        len = 0;
    }

    /* Allocate memory for the sanitized URL */
    sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        return 0;
    }

    /* Copy the URL without the protocol */
    ptr = sanitized_url;
    if (len > 0) {
        strncpy(ptr, url + len, MAX_URL_LENGTH - len - 1);
        ptr += MAX_URL_LENGTH - len - 1;
    } else {
        strcpy(ptr, url);
    }

    /* Replace invalid characters with underscores */
    while (*ptr) {
        if (!isalnum(*ptr) && *ptr!= '.' && *ptr!= '-' && *ptr!= '_') {
            *ptr = '_';
        }
        ptr++;
    }

    /* Terminate the sanitized URL */
    *ptr = '\0';

    return 1;
}

int main(int argc, char *argv[]) {
    char *url = argv[1];
    char *sanitized_url = NULL;

    /* Sanitize the URL */
    if (sanitize_url(url, sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
        return 0;
    } else {
        printf("Failed to sanitize URL.\n");
        return 1;
    }
}