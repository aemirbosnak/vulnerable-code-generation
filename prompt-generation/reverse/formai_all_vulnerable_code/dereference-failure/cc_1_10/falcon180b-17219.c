//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    if (c == '.') {
        return 1;
    }
    if (c == '_') {
        return 1;
    }
    if (c == '~') {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char** argv) {
    char url[MAX_LENGTH] = {0};
    int i = 0;
    while (i < argc) {
        strcat(url, argv[i]);
        if (i < argc - 1) {
            strcat(url, " ");
        }
        i++;
    }
    if (is_valid_url(url)) {
        printf("Valid URL: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }
    return 0;
}