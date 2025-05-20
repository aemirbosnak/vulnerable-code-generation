//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 1024
#define POLLING_INTERVAL_SEC 60

typedef struct {
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    time_t last_check_time;
} website_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_ALL);
}

void cleanup_curl() {
    curl_global_cleanup();
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_t *website = userp;
    if (size * nmemb > MAX_RESPONSE_LEN - strlen(website->response)) {
        return 0;
    }
    strncat(website->response, (char*)ptr, size * nmemb);
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
        if (res!= CURLE_OK) {
            printf("Failed to check website: %s\n", curl_easy_strerror(res));
            return 0;
        }

        time_t current_time = time(NULL);
        if (current_time - website->last_check_time > POLLING_INTERVAL_SEC) {
            printf("Website is up.\n");
        } else {
            printf("Website is still up.\n");
        }

        website->last_check_time = current_time;
        curl_easy_cleanup(curl);
        return 1;
    }

    return 0;
}

int main() {
    website_t website = {0};

    init_curl();

    while (1) {
        printf("Enter website URL: ");
        scanf("%s", website.url);

        printf("Enter initial response (leave blank for none): ");
        scanf("%[^\n]", website.response);

        website.last_check_time = time(NULL);

        while (1) {
            sleep(POLLING_INTERVAL_SEC);
            if (!check_website(&website)) {
                break;
            }
        }
    }

    cleanup_curl();
    return 0;
}