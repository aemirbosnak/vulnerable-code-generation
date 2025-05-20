//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024
#define MAX_ERROR_LENGTH 2048
#define CHECK_INTERVAL 60 // seconds

typedef struct {
    char url[MAX_URL_LENGTH];
    char error[MAX_ERROR_LENGTH];
    time_t last_checked;
    time_t next_check;
} website_t;

void init_website(website_t *website, const char *url) {
    strcpy(website->url, url);
    strcpy(website->error, "");
    website->last_checked = 0;
    website->next_check = time(NULL) + CHECK_INTERVAL;
}

size_t write_error(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_t *website = (website_t *)userp;
    size_t realsize = size * nmemb;
    if (website->error[0] == '\0') {
        strncpy(website->error, (char *)ptr, realsize > MAX_ERROR_LENGTH? MAX_ERROR_LENGTH : realsize);
    }
    return realsize;
}

int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_error);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "Failed to check website '%s': %s\n", website->url, curl_easy_strerror(res));
        } else {
            website->last_checked = time(NULL);
        }
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
    }
    curl_global_cleanup();
    return res == CURLE_OK;
}

int main() {
    website_t website;
    while (1) {
        time_t now = time(NULL);
        if (now >= website.next_check) {
            check_website(&website);
            website.next_check = now + CHECK_INTERVAL;
        }
        sleep(1);
    }
    return 0;
}