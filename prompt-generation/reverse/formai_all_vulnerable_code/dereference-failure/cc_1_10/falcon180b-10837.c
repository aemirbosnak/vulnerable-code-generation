//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i = 0;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = tolower(url[i]);
        } else {
            sanitized_url[i] = '_';
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *data = malloc(realsize + 1);
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [URL]\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    if (!is_valid_url(url)) {
        printf("Invalid URL\n");
        return 1;
    }

    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    free(sanitized_url);
    return 0;
}