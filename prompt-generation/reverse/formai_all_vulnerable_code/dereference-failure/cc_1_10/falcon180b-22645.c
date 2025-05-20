//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1000
#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 4096

struct http_request {
    char *url;
    char *request;
    size_t request_size;
};

struct http_response {
    char *response;
    size_t response_size;
};

size_t write_response_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    struct http_response *response = (struct http_response *)userp;
    size_t new_size = size * nmemb;
    if (response->response_size + new_size > response->response_size) {
        response->response_size += new_size;
        response->response = (char *)realloc(response->response, response->response_size);
    }
    memcpy(response->response + response->response_size - 1, ptr, new_size);
    response->response_size += new_size;
    return new_size;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    struct http_request request;
    struct http_response response;

    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    request.url = argv[1];
    request.request_size = strlen(request.url);
    request.request = (char *)malloc(request.request_size + 1);
    strcpy(request.request, request.url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, request.url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    printf("Response:\n%s\n", response.response);

    curl_global_cleanup();
    free(request.request);
    free(response.response);

    return 0;
}