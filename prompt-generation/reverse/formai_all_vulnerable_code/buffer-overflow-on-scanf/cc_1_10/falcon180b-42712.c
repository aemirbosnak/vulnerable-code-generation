//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048
#define MAX_RESPONSE_SIZE 1024

struct memoryStruct {
    char *response;
    size_t size;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct memoryStruct *mem = (struct memoryStruct *)userp;

    mem->response = (char *)realloc(mem->response, mem->size + realsize + 1);
    if (mem->response == NULL) {
        fprintf(stderr, "Failed to realloc memory\n");
        return 0;
    }

    memcpy(&(mem->response[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->response[mem->size] = '\0';

    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_SIZE];
    struct memoryStruct chunk;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) {
        printf("Enter the URL: ");
        scanf("%s", url);

        chunk.response = malloc(1);
        chunk.size = 0;

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", chunk.response);
        }

        curl_easy_cleanup(curl);
        free(chunk.response);
    }

    curl_global_cleanup();

    return 0;
}