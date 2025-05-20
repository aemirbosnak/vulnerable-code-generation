//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

/**
 * Remove all illegal characters from a URL.
 */
char* sanitize_url(const char* url) {
    // Define a regular expression to match any illegal characters
    const char* pattern = "[^a-zA-Z0-9_\\-\\./:?=]";

    // Compile the regular expression
    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Error compiling regex\n");
        return strdup(url); // Return the original URL if there was an error
    }

    // Perform the substitution
    char* sanitized = NULL;
    size_t url_len = strlen(url);
    int result = 0;
    regmatch_t match;
    char* last = NULL;
    while (regexec(&regex, url, 1, &match, 0) == 0) {
        size_t match_len = match.rm_eo - match.rm_so;
        sanitized = realloc(sanitized, url_len + 1 - match_len);
        strncpy(sanitized, url, match.rm_so);
        sanitized[match.rm_so] = '\0';
        last = url + match.rm_eo;
        url_len -= match_len;
        url = last;
        result++;
    }
    sanitized = (sanitized == NULL) ? strdup(url) : realloc(sanitized, url_len + 1);
    strcat(sanitized, last);

    // Clean up
    regfree(&regex);

    return sanitized;
}

int main(int argc, char** argv) {
    char* url = strdup(argv[1]);
    char* sanitized = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized);

    free(url);
    free(sanitized);
    return 0;
}