//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX_URL_LEN 1024
#define TIMEOUT 10

typedef struct {
    char url[MAX_URL_LEN];
    char last_response[MAX_URL_LEN];
    time_t last_check;
    int status;
} website_t;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_t *website = (website_t*)userp;
    strncat(website->last_response, (char*)ptr, size*nmemb);
    return size*nmemb;
}

int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            website->status = 1;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return website->status;
}

void update_status(website_t *website) {
    time_t now = time(NULL);

    if(now - website->last_check >= 60) {
        if(check_website(website)) {
            printf("Website %s is up.\n", website->url);
        } else {
            printf("Website %s is down.\n", website->url);
        }

        strcpy(website->last_response, "");
        website->last_check = now;
    }
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    website_t website;
    strcpy(website.url, argv[1]);
    website.status = -1;
    website.last_check = 0;

    while(1) {
        update_status(&website);
        sleep(60);
    }

    return 0;
}