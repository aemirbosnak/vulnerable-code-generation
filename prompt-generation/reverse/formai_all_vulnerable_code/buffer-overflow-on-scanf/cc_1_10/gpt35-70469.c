//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <time.h>

bool website_up(char *url) {
    CURL *curl_handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl_handle = curl_easy_init();
    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl_handle);

        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code == 200) {
                return true;
            }
        }

        curl_easy_cleanup(curl_handle);
    }

    curl_global_cleanup();

    return false;
}

int main()
{
    char website_url[100];
    bool is_running = true;
    time_t last_running_time = time(NULL);

    printf("Enter website URL to monitor: ");
    scanf("%s", website_url);

    while(is_running) {
        if(website_up(website_url)) {
            printf("%s is up and running!\n", website_url);
            last_running_time = time(NULL);
        } else {
            printf("%s is down! Last running time: %s", website_url, ctime(&last_running_time));
        }

        sleep(60); // Check every minute
    }

    return 0;
}