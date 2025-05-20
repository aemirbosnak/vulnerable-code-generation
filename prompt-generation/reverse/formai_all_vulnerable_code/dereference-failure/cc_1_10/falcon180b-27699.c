//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 2048
#define MAX_RESPONSE_LEN 4096

typedef struct {
    char *url;
    char *response;
    size_t response_len;
} Request;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    Request *request = (Request *) userp;
    size_t new_len = request->response_len + size * nmemb;
    request->response = realloc(request->response, new_len + 1);
    if (request->response == NULL) {
        fprintf(stderr, "Failed to reallocate memory\n");
        exit(1);
    }
    memcpy(&request->response[request->response_len], contents, size * nmemb);
    request->response_len = new_len;
    request->response[new_len] = '\0';
    return size * nmemb;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    Request request = {.url = argv[1],.response = NULL,.response_len = 0 };
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Failed to initialize curl\n");
        exit(1);
    }

    res = curl_easy_setopt(curl, CURLOPT_URL, request.url);
    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to set URL: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to set write callback: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to perform request: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    printf("Response:\n%s\n", request.response);

    free(request.response);
    free(request.url);
    return 0;
}