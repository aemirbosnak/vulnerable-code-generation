//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program takes an input URL and sanitizes it to remove any malicious code or injections.
 * It also checks to make sure the URL adheres to a certain format for security purposes.
 * Written by Your Name.
 */

int main(int argc, char *argv[]) {
    char url[256];
    char *scheme, *hostname, *path;
    int port = 80;

    if (argc == 2) {
        strcpy(url, argv[1]);
    } else {
        printf("Enter a URL to sanitize: ");
        fgets(url, sizeof(url), stdin);
        url[strcspn(url, "\n")] = 0;
    }

    scheme = strstr(url, "://");
    if (scheme == NULL) {
        printf("Invalid URL: missing scheme\n");
        return EXIT_FAILURE;
    }
    *scheme = '\0';
    scheme += 3; // move past the ://

    // check for valid scheme
    if (strcasecmp(scheme, "http") != 0 && strcasecmp(scheme, "https") != 0) {
        printf("Invalid URL: invalid scheme\n");
        return EXIT_FAILURE;
    }

    hostname = scheme + strspn(scheme, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-");
    if (*hostname == '/') {
        *hostname = '\0';
        path = hostname + 1; // move past the slash
    } else if (*hostname == ':') {
        *hostname = '\0';
        hostname++;
        port = strtol(hostname, &path, 10);
        if (port <= 0 || port > 65535) {
            printf("Invalid URL: invalid port\n");
            return EXIT_FAILURE;
        }
        if (*path != '/') {
            printf("Invalid URL: missing path\n");
            return EXIT_FAILURE;
        }
        path++;
    } else {
        printf("Invalid URL: missing path\n");
        return EXIT_FAILURE;
    }

    // check for potential malicious code
    if (strstr(path, "<script>") != NULL || strstr(path, "</script>") != NULL) {
        printf("Sanitized URL: %s://%s:%d%s\n", scheme, hostname, port, "/");
        return EXIT_SUCCESS;
    }

    // sanitize input to remove potential malicious code
    char *result = malloc(strlen(path) + 1);
    if (result == NULL) {
        printf("Error: insufficient memory available\n");
        return EXIT_FAILURE;
    }
    char *src, *dst;
    for (src = path, dst = result; *src != '\0'; src++, dst++) {
        if (*src == '<') {
            strncpy(dst, "&lt;", 4);
            dst += 3;
        } else if (*src == '>') {
            strncpy(dst, "&gt;", 4);
            dst += 3;
        } else {
            *dst = *src;
        }
    }
    *dst = '\0';

    printf("Sanitized URL: %s://%s:%d%s\n", scheme, hostname, port, result);

    free(result);

    return EXIT_SUCCESS;
}