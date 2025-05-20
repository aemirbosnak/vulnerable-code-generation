//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define CHECK_INTERVAL 60 // Check website every 60 seconds

int is_website_up(const char *url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "Failed to check website: %s\n", curl_easy_strerror(res));
        } else {
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if (http_code >= 200 && http_code < 400) {
                return 1;
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}

void send_notification(const char *subject, const char *body) {
    // Implement sending notification here
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];
    time_t last_check_time = 0;

    while (1) {
        time_t current_time = time(NULL);
        if (current_time - last_check_time >= CHECK_INTERVAL) {
            int website_status = is_website_up(url);
            if (website_status == 0) {
                send_notification("Website is down", "The website is currently down. Please check it.");
            } else if (website_status == 1) {
                send_notification("Website is up", "The website is back up and running.");
            }

            last_check_time = current_time;
        }

        sleep(1);
    }

    return 0;
}