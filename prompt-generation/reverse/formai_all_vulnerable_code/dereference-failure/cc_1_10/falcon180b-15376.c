//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define TIMEOUT 10
#define RETRY_LIMIT 3

typedef struct {
    char url[MAX_URL_LEN];
    time_t last_check;
    int status;
} website_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    char *data = (char *)malloc(size * nmemb);
    memcpy(data, ptr, size * nmemb);
    printf("%s", data);
    free(data);
    return nmemb;
}

int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return res;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    website_t website;
    strcpy(website.url, argv[1]);
    website.last_check = time(NULL);
    website.status = 0;

    while(1) {
        time_t current_time = time(NULL);
        if(difftime(current_time, website.last_check) >= TIMEOUT) {
            int retry_count = 0;
            while(retry_count < RETRY_LIMIT) {
                int result = check_website(&website);
                if(result == CURLE_OK) {
                    website.last_check = current_time;
                    if(website.status == 0) {
                        printf("Website is up.\n");
                        website.status = 1;
                    }
                } else {
                    retry_count++;
                    sleep(1);
                }
            }
            if(retry_count == RETRY_LIMIT) {
                printf("Website is down.\n");
                website.status = 0;
            }
        }
        sleep(1);
    }

    return 0;
}