//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048
#define MAX_REDIRECTS 10

typedef struct {
    char *url;
    int redirect_count;
} URLInfo;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *data = (char*)malloc(size * nmemb);
    memcpy(data, contents, size * nmemb);
    printf("%s", data);
    free(data);
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s URL\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    char *url = argv[1];
    int max_redirects = MAX_REDIRECTS;
    int redirect_count = 0;
    URLInfo *url_info = malloc(sizeof(URLInfo));

    url_info->url = url;
    url_info->redirect_count = redirect_count;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, max_redirects);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    free(url_info);

    return 0;
}