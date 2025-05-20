//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/time.h>

#define MAX_URL_LEN 1024
#define SLEEP_SECONDS 60
#define CHECK_INTERVAL 5

typedef struct {
    char *url;
    time_t last_checked;
    int status;
} website_t;

void website_init(website_t *website) {
    website->url = NULL;
    website->last_checked = 0;
    website->status = 0;
}

void website_cleanup(website_t *website) {
    if (website->url!= NULL) {
        free(website->url);
        website->url = NULL;
    }
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *fp;
    char readBuffer[1024];
    website_t websites[] = {{"http://www.google.com", 0, 0}, {"http://www.yahoo.com", 0, 0}};
    int numWebsites = sizeof(websites) / sizeof(website_t);
    int i;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        for (i = 0; i < numWebsites; i++) {
            website_init(&websites[i]);
        }

        while (1) {
            time_t currentTime = time(NULL);

            for (i = 0; i < numWebsites; i++) {
                if (currentTime - websites[i].last_checked >= CHECK_INTERVAL) {
                    websites[i].status = 0;

                    curl_easy_setopt(curl, CURLOPT_URL, websites[i].url);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &websites[i]);

                    if (curl_easy_perform(curl)!= CURLE_OK) {
                        websites[i].status = -1;
                    } else {
                        websites[i].status = 1;
                    }

                    websites[i].last_checked = currentTime;
                }
            }

            sleep(SLEEP_SECONDS);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}