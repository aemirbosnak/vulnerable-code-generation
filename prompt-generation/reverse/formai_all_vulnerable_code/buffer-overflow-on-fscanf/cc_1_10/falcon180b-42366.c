//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 1024
#define CHECK_INTERVAL 60 // in seconds

typedef struct {
    char *url;
    char *response;
    time_t last_check;
} website_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_t *website = (website_t*)userp;
    size_t new_len = website->response? strlen(website->response) + size * nmemb : size * nmemb;
    website->response = realloc(website->response, new_len + 1);
    if (!website->response) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }
    memcpy(website->response + strlen(website->response), ptr, size * nmemb);
    website->response[new_len] = '\0';
    return size * nmemb;
}

int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Error: failed to initialize curl\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, website->url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "Error: failed to fetch website (%d)\n", res);
        curl_easy_cleanup(curl);
        return 1;
    }

    curl_easy_cleanup(curl);
    return 0;
}

int main() {
    website_t *websites = NULL;
    int num_websites = 0;
    FILE *config_file = fopen("config.txt", "r");

    if (!config_file) {
        fprintf(stderr, "Error: failed to open config file\n");
        return 1;
    }

    while (fscanf(config_file, "%s\n", websites[num_websites].url)!= EOF) {
        num_websites++;
        websites = realloc(websites, sizeof(website_t) * num_websites);
    }

    fclose(config_file);

    init_curl();

    while (1) {
        sleep(CHECK_INTERVAL);

        for (int i = 0; i < num_websites; i++) {
            time_t current_time = time(NULL);
            if (difftime(current_time, websites[i].last_check) >= CHECK_INTERVAL) {
                int result = check_website(&websites[i]);
                if (result) {
                    fprintf(stderr, "Error: website %s is down\n", websites[i].url);
                }
            }
        }
    }

    return 0;
}