//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define MAX_POST_SIZE 1024

struct {
    char *url;
    char *post_data;
    int post_size;
} request_data;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *data = (char*)malloc(realsize + 1);
    if (data == NULL) {
        return 0;
    }
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        printf("Usage: %s <URL> <POST_DATA>\n", argv[0]);
        return 1;
    }

    strncpy(request_data.url, argv[1], MAX_URL_SIZE);
    request_data.post_data = argv[2];
    request_data.post_size = strlen(request_data.post_data);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, request_data.url);
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request_data.post_data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, request_data.post_size);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return 0;
}