//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*)malloc(realsize + 1);
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    ((char**)userp)[0] = data;
    return realsize;
}

int main(int argc, char** argv) {
    CURL* curl;
    CURLcode res;
    char url[100];
    char* response;

    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}