//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <sys/time.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024

struct url_data {
    char url[MAX_URL_LENGTH];
    time_t last_check;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    struct url_data *data = (struct url_data *)userp;
    if (data->last_check == 0) {
        data->last_check = time(NULL);
    }
    strncat(data->url, (char *)contents, MAX_RESPONSE_LENGTH - strlen(data->url) - 1);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    struct url_data urls[10];
    int num_urls = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        while (num_urls < 10 && scanf("%s", urls[num_urls].url)!= EOF) {
            urls[num_urls].last_check = 0;
            num_urls++;
        }

        for (int i = 0; i < num_urls; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urls[i]);
            res = curl_easy_perform(curl);

            if (res!= CURLE_OK) {
                fprintf(stderr, "Failed to check %s: %s\n", urls[i].url, curl_easy_strerror(res));
            } else {
                printf("%s is up\n", urls[i].url);
            }
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}