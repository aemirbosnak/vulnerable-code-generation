//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*) malloc(realsize + 1);
    if (!data) {
        return 0;
    }
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    char* sanitized_url = (char*) malloc(strlen(url) + 1);
    if (!sanitized_url) {
        printf("Error: Could not allocate memory for sanitized URL.\n");
        return 1;
    }

    char* p = sanitized_url;
    for (char* q = url; *q; q++) {
        if (isalnum(*q) || *q == '-') {
            *p++ = *q;
        }
    }
    *p = '\0';

    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            printf("Success!\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    } else {
        printf("Error: Could not initialize libcurl.\n");
    }

    free(sanitized_url);
    return 0;
}