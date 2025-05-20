//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>

#define MAX_URLS 10

typedef struct {
    char url[100];
    int http_status;
    int response_time;
} URL;

void monitor_urls(URL* urls) {
    int i;
    CURL *curl;
    CURLcode res;
    double time_taken;
    struct curl_slist *headers = NULL;

    curl = curl_easy_init();
    if (curl) {
        for (i=0; i<MAX_URLS; i++) {
            headers = NULL;

            headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0");
            headers = curl_slist_append(headers, "Accept: */*");

            curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

            usleep(500000);
            res = curl_easy_perform(curl);

            if (res == CURLE_OK) {
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &urls[i].http_status);
                curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time_taken);

                urls[i].response_time = (int) (time_taken * 1000);
            }
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    URL urls[MAX_URLS] = {
        {"https://www.google.com", 0, 0},
        {"https://www.yahoo.com", 0, 0},
        {"https://www.bing.com", 0, 0},
        {"https://www.msn.com", 0, 0},
        {"https://www.reddit.com", 0, 0},
        {"https://www.twitter.com", 0, 0},
        {"https://www.facebook.com", 0, 0},
        {"https://www.linkedin.com", 0, 0},
        {"https://www.github.com", 0, 0},
        {"https://www.nytimes.com", 0, 0},
    };

    for (;;) {
        monitor_urls(urls);

        printf("%20s | %10s | %12s\n", "URL", "Status", "Response Time");
        printf("--------------------------------------------------\n");

        int all_ok = 1;
        for (int i=0; i<MAX_URLS; i++) {
            printf("%20s | %10d | %12dms\n", urls[i].url, urls[i].http_status, urls[i].response_time);
            if (urls[i].http_status != 200) {
                all_ok = 0;
            }
        }

        if (all_ok) {
            printf("All websites are up and running\n");
        }

        printf("\n");
        sleep(10);
    }

    return 0;
}