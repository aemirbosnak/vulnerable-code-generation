//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_WEBSITE_COUNT 10
#define CHECK_INTERVAL_SEC 60

struct website_info {
    char name[50];
    char url[100];
    FILE *log_file;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main() {
    CURL *curl;
    FILE *log_file;
    struct website_info websites[MAX_WEBSITE_COUNT];
    int num_websites = 0;
    time_t last_check_time = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        printf("Error initializing curl\n");
        return 1;
    }

    while (1) {
        time_t current_time = time(NULL);
        if (current_time - last_check_time >= CHECK_INTERVAL_SEC) {
            last_check_time = current_time;

            for (int i = 0; i < num_websites; i++) {
                websites[i].log_file = fopen(websites[i].name, "a");
                if (!websites[i].log_file) {
                    printf("Error opening log file for %s\n", websites[i].name);
                    continue;
                }

                curl_easy_setopt(curl, CURLOPT_URL, websites[i].url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, websites[i].log_file);

                CURLcode res = curl_easy_perform(curl);
                if (res!= CURLE_OK) {
                    printf("Error checking %s: %s\n", websites[i].url, curl_easy_strerror(res));
                } else {
                    printf("Checked %s\n", websites[i].url);
                }

                fclose(websites[i].log_file);
            }
        }

        sleep(1);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}