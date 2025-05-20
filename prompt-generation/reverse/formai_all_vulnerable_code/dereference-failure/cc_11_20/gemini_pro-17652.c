//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <curl/curl.h>

// Custom function to escape special characters in a string
char *escape_special_chars(char *str) {
    size_t len = strlen(str);
    char *escaped_str = malloc(len * 3 + 1);  // Allocate enough space for escaped characters
    if (!escaped_str) {
        return NULL;
    }

    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
            str[i] == '\\' || str[i] == '\'' || str[i] == '\"' || str[i] == ';' ||
            str[i] == '&' || str[i] == '<' || str[i] == '>' || str[i] == '`') {
            escaped_str[j++] = '\\';
        }
        escaped_str[j++] = str[i++];
    }
    escaped_str[j] = '\0';

    return escaped_str;
}

int main(int argc, char **argv) {
    // Check if the user provided a URL as an argument
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Initialize the CURL state
    CURL *curl = curl_easy_init();
    if (!curl) {
        perror("curl_easy_init() failed");
        return 2;
    }

    // Set the URL to be sanitized
    char *url = argv[1];

    // Allocate a buffer to store the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);
    if (!sanitized_url) {
        perror("malloc() failed");
        return 3;
    }

    // Create the regular expression pattern to match invalid characters
    const char *pattern = "[^a-zA-Z0-9\\-_\\.~:/\\?#\\([\\)]|=]";
    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        perror("regcomp() failed");
        return 4;
    }

    // Iterate over the URL and replace invalid characters with their escaped counterparts
    int i = 0;
    while (url[i]) {
        if (regexec(&regex, &url[i], 0, NULL, 0) == 0) {
            char *escaped_char = escape_special_chars(&url[i]);
            if (!escaped_char) {
                perror("escape_special_chars() failed");
                return 5;
            }
            strcat(sanitized_url, escaped_char);
            free(escaped_char);
        } else {
            strncat(sanitized_url, &url[i], 1);
        }
        i++;
    }

    regfree(&regex);
    curl_easy_cleanup(curl);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}