//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty URL sanitizer function
char *sanitize_url(const char *url) {
    size_t len = strlen(url);
    char *sanitized = malloc(len + 1);
    if (!sanitized) return NULL;

    char *dst = sanitized;
    for (const char *src = url; *src; src++) {
        switch (*src) {
            case ' ':
                *dst++ = '+';
                break;
            case '%':
                if (src[1] && src[2]) {
                    char hex[3] = {src[1], src[2], '\0'};
                    unsigned int code;
                    sscanf(hex, "%x", &code);
                    if (code < 128) {
                        *dst++ = (char)code;
                        src += 2;
                    } else {
                        *dst++ = *src++;
                        *dst++ = *src;
                    }
                } else {
                    *dst++ = *src;
                }
                break;
            default:
                *dst++ = *src;
        }
    }
    *dst = '\0';
    return sanitized;
}

// Let's spice things up with a silly URL
const char *url = "http://www.example.com/path/to/fun?query=string%20with%20spaces";

int main() {
    printf("Original URL: %s\n", url);

    // Sanitize that URL like a pro
    char *sanitized = sanitize_url(url);
    if (!sanitized) {
        printf("Oops, something went wrong while sanitizing the URL!\n");
        return EXIT_FAILURE;
    }

    printf("Sanitized URL: %s\n", sanitized);
    printf("Safe for sharing your hilarious cat videos!\n");

    free(sanitized);
    return EXIT_SUCCESS;
}