//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define INTERVAL 60

struct website_info {
    char *url;
    char *last_response;
    time_t last_check;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char *)ptr;
    size_t buffer_size = size * nmemb;
    struct website_info *info = (struct website_info *)userp;

    if (buffer_size > BUFFER_SIZE) {
        buffer_size = BUFFER_SIZE;
    }

    strncpy(info->last_response, buffer, buffer_size);
    info->last_response[buffer_size - 1] = '\0';

    return buffer_size;
}

int check_website(struct website_info *info) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, info->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, info);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return res;
}

int main() {
    struct website_info websites[] = {
        {"https://www.google.com", NULL, 0},
        {"https://www.yahoo.com", NULL, 0},
        {"https://www.bing.com", NULL, 0}
    };

    int num_websites = sizeof(websites) / sizeof(struct website_info);

    while (1) {
        for (int i = 0; i < num_websites; i++) {
            time_t current_time = time(NULL);

            if (current_time - websites[i].last_check >= INTERVAL) {
                check_website(&websites[i]);
                websites[i].last_check = current_time;
            }
        }

        sleep(INTERVAL);
    }

    return 0;
}