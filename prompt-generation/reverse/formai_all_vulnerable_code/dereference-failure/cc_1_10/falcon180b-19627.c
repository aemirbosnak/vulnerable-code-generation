//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define BUFFER_SIZE 4096

struct {
    char *url;
    char *method;
    struct curl_slist *headers;
} request;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *ptr = (char*)contents;
    while(realsize-- > 0) {
        fwrite(ptr, 1, 1, stdout);
        ptr++;
    }
    return realsize;
}

int main(int argc, char *argv[]) {
    if(argc!= 4) {
        printf("Usage: %s <method> <url> <headers>\n", argv[0]);
        return 1;
    }

    request.method = argv[1];
    strncpy(request.url, argv[2], MAX_URL_SIZE);
    request.url[MAX_URL_SIZE - 1] = '\0';
    request.headers = curl_slist_append(NULL, argv[3]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, request.url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request.method);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, request.headers);

        CURLcode res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(request.headers);
        curl_global_cleanup();
    }

    return 0;
}