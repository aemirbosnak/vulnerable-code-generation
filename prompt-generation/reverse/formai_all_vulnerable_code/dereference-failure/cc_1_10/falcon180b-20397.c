//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define MAX_RESPONSE_SIZE 1024

typedef struct {
    char *url;
    char *response;
    int response_code;
} Request;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    Request *request = (Request *) userp;
    size_t realsize = size * nmemb;
    strncat(request->response, (char *) contents, realsize);
    return realsize;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_SIZE];
    strcpy(url, argv[1]);

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        Request request;
        request.url = url;
        request.response = (char *) malloc(MAX_RESPONSE_SIZE);
        request.response[0] = '\0';

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &request);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}