//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || strchr("!#$&'()*+,-./:;=?@[\\]^_`{|}~", c)!= NULL) {
        return 1;
    }
    return 0;
}

int url_encode(char *dest, const char *src, int dest_size) {
    char hex[3];
    int len = 0;
    while (*src && len < dest_size - 3) {
        if (is_valid_url_char(*src)) {
            *dest++ = *src++;
            len++;
        } else {
            sprintf(hex, "%%%02X", *src++);
            strcpy(dest, hex);
            dest += 3;
            len += 3;
        }
    }
    *dest = '\0';
    return len;
}

void sanitize_url(char *url) {
    char *p = url;
    char *q = malloc(MAX_URL_LEN);
    if (q == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    int len = 0;
    while (*p && len < MAX_URL_LEN - 1) {
        if (*p == '%') {
            if (isxdigit(p[1]) && isxdigit(p[2])) {
                sprintf(q, "%c%c", p[1], p[2]);
                p += 3;
            } else {
                *q++ = *p++;
                len++;
            }
        } else {
            *q++ = *p++;
            len++;
        }
    }
    *q = '\0';
    strcpy(url, q);
    free(q);
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}