//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define TIMEOUT 10
#define RETRY_INTERVAL 30

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char *) malloc(size * nmemb);
    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    free(buffer);
    return size * nmemb;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl == NULL) {
        fprintf(stderr, "Failed to initialize curl\n");
        exit(EXIT_FAILURE);
    }

    char url[MAX_URL_LEN];
    strncpy(url, argv[1], MAX_URL_LEN - 1);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

    res = curl_easy_perform(curl);

    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to perform curl request: %s\n", curl_easy_strerror(res));
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}