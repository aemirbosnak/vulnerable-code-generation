//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_URL_LEN 2048

int main() {
    char url[MAX_URL_LEN];
    char sanitizedURL[MAX_URL_LEN];
    const char *pattern = "^(https?://)?(www\\.)?([a-zA-Z0-9]+\\.)+[a-zA-Z0-9]{2,4}(/.*)?$";
    regex_t regex;
    int reti;

    printf("Enter a URL: ");
    scanf("%s", url);

    // Compile the regular expression
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile the regular expression: %s\n", strerror(reti));
        return EXIT_FAILURE;
    }

    // Perform the matching
    reti = regexec(&regex, url, 0, NULL, 0);
    if (reti == 0) {
        // The URL is valid, so sanitize it
        strcpy(sanitizedURL, url);
        // Remove the scheme (http:// or https://)
        if (strstr(sanitizedURL, "://")) {
            char *scheme_end = strstr(sanitizedURL, "://") + 3;
            memmove(sanitizedURL, scheme_end, strlen(scheme_end) + 1);
        }
        // Remove the www. prefix
        if (strstr(sanitizedURL, "www.")) {
            char *www_end = strstr(sanitizedURL, "www.") + 4;
            memmove(sanitizedURL, www_end, strlen(www_end) + 1);
        }
        // Remove any trailing slashes
        if (sanitizedURL[strlen(sanitizedURL) - 1] == '/') {
            sanitizedURL[strlen(sanitizedURL) - 1] = '\0';
        }
        // Print the sanitized URL
        printf("Sanitized URL: %s\n", sanitizedURL);
    } else if (reti == REG_NOMATCH) {
        // The URL is invalid
        printf("Invalid URL: %s\n", url);
        return EXIT_FAILURE;
    } else {
        // An error occurred
        fprintf(stderr, "An error occurred while matching the regular expression: %s\n", strerror(reti));
        return EXIT_FAILURE;
    }

    // Free the compiled regular expression
    regfree(&regex);

    return EXIT_SUCCESS;
}