//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *data;
    size_t size;
} Response;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    Response *response = (Response *)userp;
    size_t realsize = size * nmemb;
    if (response->size + realsize >= response->size) {
        response->size += 1024;
        response->data = realloc(response->data, response->size);
    }
    memcpy(&response->data[response->size - 1], contents, realsize);
    response->size += realsize;
    return realsize;
}

int main()
{
    CURL *curl;
    CURLcode res;
    Response response;
    response.data = malloc(1);
    response.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts/1");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response.data);
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return 0;
}