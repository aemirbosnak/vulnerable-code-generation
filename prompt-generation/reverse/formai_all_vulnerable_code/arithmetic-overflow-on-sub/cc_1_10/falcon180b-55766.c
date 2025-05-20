//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define SITE_URL "http://example.com"
#define CHECK_INTERVAL 60 // in seconds
#define MAX_FAILURES 3
#define FAILURE_THRESHOLD_SECONDS 1800 // 30 minutes

struct site_status {
    char *url;
    time_t last_check;
    int failures;
};

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int check_site(struct site_status *site) {
    CURL *curl;
    CURLcode res;
    char *response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "Failed to check site: %s\n", curl_easy_strerror(res));
        } else {
            site->last_check = time(NULL);
            site->failures = 0;
        }

        curl_easy_cleanup(curl);
    }

    return res;
}

int main() {
    struct site_status site = {
       .url = SITE_URL,
       .last_check = 0,
       .failures = 0
    };

    while(1) {
        time_t now = time(NULL);
        time_t elapsed = now - site.last_check;

        if(elapsed >= CHECK_INTERVAL) {
            int res = check_site(&site);

            if(res!= CURLE_OK) {
                site.failures++;

                if(site.failures >= MAX_FAILURES) {
                    fprintf(stderr, "Site down for more than %d seconds\n", FAILURE_THRESHOLD_SECONDS);
                    exit(1);
                }
            } else {
                site.failures = 0;
            }

            site.last_check = now;
        }

        sleep(1);
    }

    return 0;
}