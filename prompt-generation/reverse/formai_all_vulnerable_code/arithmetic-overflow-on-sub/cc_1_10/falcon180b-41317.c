//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 1024
#define CHECK_INTERVAL_SECONDS 60

struct website_info {
    char url[MAX_URL_LENGTH];
    time_t last_checked;
    int is_up;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *fp;
    char buffer[MAX_URL_LENGTH];
    struct website_info websites[10];
    int num_websites = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        while (num_websites < 10) {
            printf("Enter website URL (or type 'done' to finish): ");
            fgets(buffer, MAX_URL_LENGTH, stdin);

            if (strcmp(buffer, "done") == 0) {
                break;
            }

            strcpy(websites[num_websites].url, buffer);
            websites[num_websites].last_checked = time(NULL);
            websites[num_websites].is_up = 1;
            num_websites++;
        }

        while (1) {
            time_t current_time = time(NULL);

            for (int i = 0; i < num_websites; i++) {
                if (current_time - websites[i].last_checked >= CHECK_INTERVAL_SECONDS) {
                    char url_copy[MAX_URL_LENGTH];
                    strcpy(url_copy, websites[i].url);

                    curl_easy_setopt(curl, CURLOPT_URL, url_copy);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &websites[i].url);

                    CURLcode res = curl_easy_perform(curl);

                    if (res!= CURLE_OK) {
                        websites[i].is_up = 0;
                    } else {
                        websites[i].is_up = 1;
                    }

                    websites[i].last_checked = current_time;
                }
            }

            sleep(1);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}