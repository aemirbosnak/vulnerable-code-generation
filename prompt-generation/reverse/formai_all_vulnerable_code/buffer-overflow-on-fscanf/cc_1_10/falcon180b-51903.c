//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LEN 2048
#define MAX_STATUS_LEN 100
#define CHECK_INTERVAL 60 // seconds

struct url_status {
    char url[MAX_URL_LEN];
    char status[MAX_STATUS_LEN];
    time_t last_checked;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int main() {
    CURL* curl;
    FILE* fp;
    char buffer[MAX_STATUS_LEN];
    struct url_status urls[10];
    int num_urls = 0;
    time_t current_time, next_check_time;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        fp = fopen("urls.txt", "r");
        if (fp) {
            while (fscanf(fp, "%s", urls[num_urls].url)!= EOF && num_urls < 10) {
                strcpy(urls[num_urls].status, "N/A");
                num_urls++;
            }
            fclose(fp);
        } else {
            printf("Error: Unable to open urls.txt\n");
            exit(1);
        }

        current_time = time(NULL);
        next_check_time = current_time + CHECK_INTERVAL;

        while (1) {
            sleep(next_check_time - current_time);
            current_time = time(NULL);

            for (int i = 0; i < num_urls; i++) {
                curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, urls[i].status);
                curl_easy_perform(curl);
            }

            next_check_time = current_time + CHECK_INTERVAL;
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}