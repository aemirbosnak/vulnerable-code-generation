//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *url;
    char *method;
    char *headers;
    char *body;
} Request;

typedef struct {
    CURL *curl;
    FILE *file;
} Response;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    Response *response = (Response *)userp;
    return fwrite(contents, realsize, 1, response->file);
}

int main() {
    CURL *curl;
    CURLcode res;
    Request request;
    Response response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        printf("Enter URL: ");
        scanf("%s", request.url);

        printf("Enter method (GET/POST): ");
        scanf("%s", request.method);

        printf("Enter headers (optional): ");
        scanf("%s", request.headers);

        printf("Enter body (optional): ");
        scanf("%s", request.body);

        response.curl = curl;
        response.file = stdout;

        curl_easy_setopt(curl, CURLOPT_URL, request.url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request.method);

        if(request.headers) {
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, request.headers);
        }

        if(request.body) {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request.body);
        }

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}