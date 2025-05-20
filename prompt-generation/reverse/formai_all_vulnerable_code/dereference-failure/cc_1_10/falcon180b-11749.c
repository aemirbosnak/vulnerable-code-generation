//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_URL_LENGTH 2048

/* Function to sanitize a URL */
char *sanitize_url(const char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (!sanitized_url) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Copy the original URL to the sanitized URL */
    strcpy(sanitized_url, url);

    /* Remove leading and trailing whitespace */
    char *ptr = sanitized_url;
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
    while (*ptr && isspace(*(ptr + strlen(ptr) - 1))) {
        ptr[strlen(ptr) - 1] = '\0';
    }

    /* Replace invalid characters with their hexadecimal representation */
    regex_t regex;
    regcomp(&regex, "[^a-zA-Z0-9.-]", REG_EXTENDED);
    ptr = sanitized_url;
    while (*ptr) {
        if (regexec(&regex, ptr, 0, 0, 0) == 0) {
            char hex[4];
            sprintf(hex, "%02X", (unsigned char)*ptr);
            strcat(sanitized_url, hex);
        } else {
            strcat(sanitized_url, ptr);
        }
        ptr++;
    }

    /* Add leading "http://" if necessary */
    if (strncmp(sanitized_url, "http://", 7)!= 0 &&
        strncmp(sanitized_url, "https://", 8)!= 0) {
        strcat(sanitized_url, "http://");
    }

    return sanitized_url;
}

/* Function to print the sanitized URL */
void print_sanitized_url(const char *url) {
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    print_sanitized_url(argv[1]);

    return 0;
}