//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define TIMEOUT 5 // seconds
#define CHECK_INTERVAL 30 // seconds

void check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1); // We only want to check the response code
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            printf("Error: Could not check %s (Curl error: %s)\n", url, curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                printf("SURPRISE! %s is UP! (Response code: %ld)\n", url, response_code);
            } else {
                printf("Oh no! %s is DOWN! (Response code: %ld)\n", url, response_code);
            }
        }
        curl_easy_cleanup(curl);
    } else {
        printf("Unexpected Error: curl_easy_init() failed!\n");
    }
}

int main() {
    char *urls[MAX_URLS];
    int url_count = 0;

    // Populating URLs for monitoring
    urls[url_count++] = "http://example.com";
    urls[url_count++] = "http://google.com";
    urls[url_count++] = "http://nonexistenturl.baddomain";
    urls[url_count++] = "http://github.com";
    urls[url_count++] = "http://stackoverflow.com";

    time_t next_check = time(NULL);

    printf("Website Uptime Monitor Initialized! 🚀\n");
    
    while (1) {
        if (time(NULL) >= next_check) {
            printf("\n--- Checking website statuses at %s ---\n", ctime(&next_check));
            for (int i = 0; i < url_count; i++) {
                check_website(urls[i]);
            }
            next_check += CHECK_INTERVAL; // Schedule next check
        }
        sleep(1); // Sleep to prevent busy waiting
    }

    return 0;
}