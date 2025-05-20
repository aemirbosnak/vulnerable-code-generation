//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 512
#define MAX_RESPONSE_LENGTH 8192
#define DEFAULT_INTERVAL 60 // seconds

typedef struct {
    char url[MAX_URL_LENGTH];
    time_t last_check;
    int status_code;
    char response[MAX_RESPONSE_LENGTH];
} website_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_t *website = (website_t*)userp;
    size_t new_length = website->status_code? strlen(website->response) : 0;
    size_t total_length = website->last_check? strlen(website->response) + new_length + 1 : new_length;
    if (total_length >= MAX_RESPONSE_LENGTH) {
        return 0;
    }
    if (new_length > 0) {
        strcat(website->response, (char*)ptr);
    }
    return size * nmemb;
}

int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            return -1;
        }
    } else {
        fprintf(stderr, "curl_easy_init() failed\n");
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <website_url> <check_interval_seconds>\n", argv[0]);
        return 1;
    }

    website_t website;
    strncpy(website.url, argv[1], MAX_URL_LENGTH);
    website.url[MAX_URL_LENGTH - 1] = '\0';
    website.last_check = time(NULL);
    website.status_code = 0;
    website.response[0] = '\0';

    int interval = atoi(argv[2]);
    if (interval <= 0) {
        interval = DEFAULT_INTERVAL;
    }

    while (1) {
        time_t current_time = time(NULL);
        if (current_time - website.last_check >= interval) {
            int result = check_website(&website);
            if (result == 0) {
                printf("Website is up\n");
            } else {
                printf("Website is down\n");
            }
            website.last_check = current_time;
        }
        sleep(interval);
    }

    return 0;
}