//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static char *strip_non_url_chars(const char *str) {
    char *new_str = malloc(strlen(str) + 1);
    if (!new_str) {
        return NULL;
    }

    int i = 0, j = 0;
    while (str[i]) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9') ||
            str[i] == '-' || str[i] == '_' || str[i] == '.' || str[i] == '~' ||
            str[i] == '/' || str[i] == ':' || str[i] == '?' || str[i] == '&' ||
            str[i] == '=' || str[i] == '+' || str[i] == '%') {
            new_str[j++] = str[i];
        }
        i++;
    }

    new_str[j] = '\0';
    return new_str;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];

    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return EXIT_FAILURE;
    }

    char *sanitized_url = strip_non_url_chars(url);
    if (!sanitized_url) {
        fprintf(stderr, "strip_non_url_chars() failed\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);
    curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    free(sanitized_url);

    return EXIT_SUCCESS;
}