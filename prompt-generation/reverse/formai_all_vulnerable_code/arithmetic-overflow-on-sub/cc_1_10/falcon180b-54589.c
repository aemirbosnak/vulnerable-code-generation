//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define CHECK_INTERVAL 60 // Check every minute
#define TIMEOUT 10 // Timeout after 10 seconds

char *website_url = "https://example.com"; // Change this to the website you want to monitor
long last_check_time = 0; // Initialize last check time to 0
int is_down = 0; // Initialize is_down flag to 0

void check_website() {
    CURL *curl;
    CURLcode res;
    long response_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website_url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code!= 200) {
                is_down = 1;
            } else {
                is_down = 0;
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    while(1) {
        time_t current_time = time(NULL);

        if(current_time - last_check_time >= CHECK_INTERVAL) {
            check_website();
            last_check_time = current_time;
        }

        if(is_down) {
            fprintf(stdout, "Website is down!\n");
        } else {
            fprintf(stdout, "Website is up!\n");
        }

        sleep(1);
    }

    return 0;
}