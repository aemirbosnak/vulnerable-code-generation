//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define CHECK_INTERVAL 60 // in seconds

typedef struct {
    char url[MAX_URL_LEN];
    time_t last_check;
    int status;
} website_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    char *data = (char*)ptr;
    size_t realsize = size * nmemb;
    printf("%s", data);
    return realsize;
}

int check_website(website_t* website) {
    CURL *curl;
    CURLcode res;
    char readBuffer[1024];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        sprintf(website->url, "http://%s", website->url);
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return res;
}

void main_loop(void) {
    website_t websites[] = {{"www.example.com", 0, 0}};
    int num_websites = sizeof(websites) / sizeof(website_t);

    while(1) {
        time_t current_time = time(NULL);

        for(int i = 0; i < num_websites; i++) {
            website_t* website = &websites[i];

            if(website->last_check + CHECK_INTERVAL < current_time) {
                int status = check_website(website);
                if(status == CURLE_OK) {
                    website->status = 200;
                } else {
                    website->status = 500;
                }
                website->last_check = current_time;
            }
        }

        sleep(CHECK_INTERVAL);
    }
}

int main(int argc, char** argv) {
    init_curl();
    main_loop();

    return 0;
}