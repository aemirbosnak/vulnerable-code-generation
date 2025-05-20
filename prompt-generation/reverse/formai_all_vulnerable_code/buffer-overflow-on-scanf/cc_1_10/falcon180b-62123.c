//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URLS 10

struct url_info {
    char *url;
    int is_up;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char*)malloc(size * nmemb);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, size * nmemb);
    *(char**)userp = buffer;
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    struct url_info urls[MAX_URLS];
    int num_urls = 0;
    char *response_buffer = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        while (num_urls < MAX_URLS && scanf("%s", urls[num_urls].url)!= EOF) {
            num_urls++;
        }

        for (int i = 0; i < num_urls; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_buffer);

            res = curl_easy_perform(curl);

            if (res!= CURLE_OK) {
                urls[i].is_up = 0;
            } else {
                urls[i].is_up = 1;
            }

            free(response_buffer);
            response_buffer = NULL;
        }

        for (int i = 0; i < num_urls; i++) {
            printf("%s is %s\n", urls[i].url, urls[i].is_up? "up" : "down");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}