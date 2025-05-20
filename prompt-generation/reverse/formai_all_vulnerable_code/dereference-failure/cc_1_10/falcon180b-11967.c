//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_LENGTH 4096

int is_valid_url(const char* url);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [URL]\n", argv[0]);
        return 1;
    }

    char* input_url = argv[1];
    int input_url_length = strlen(input_url);

    if (input_url_length > MAX_LENGTH) {
        printf("Error: URL is too long.\n");
        return 1;
    }

    if (!is_valid_url(input_url)) {
        printf("Error: Invalid URL.\n");
        return 1;
    }

    printf("Valid URL.\n");
    return 0;
}

int is_valid_url(const char* url) {
    regex_t regex;
    regmatch_t matches[3];
    char* pattern = "^((http|https|ftp)://)?([^/:]+)(:([0-9]+))?(/[^?#]*)?(\\?[^#]*)?#([^#]*)?$";

    if (regcomp(&regex, pattern, REG_EXTENDED | REG_ICASE)!= 0) {
        return 0;
    }

    if (regexec(&regex, url, 3, matches, 0)!= REG_NOMATCH) {
        regfree(&regex);
        return 1;
    }

    regfree(&regex);
    return 0;
}