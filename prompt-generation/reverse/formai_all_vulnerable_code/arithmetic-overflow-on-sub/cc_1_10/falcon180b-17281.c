//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/timeb.h>
#include <unistd.h>

#define URL "http://example.com"
#define TIMEOUT 10
#define INTERVAL 60

void log(const char* msg) {
    char timestamp[32];
    struct timeb time;
    ftime(&time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &time);
    fprintf(stderr, "[%s] %s\n", timestamp, msg);
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    char response[4096];
    struct timeb last_check;
    struct timeb current_time;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            log("Site is up");
        } else {
            log("Site is down");
        }

        curl_easy_cleanup(curl);
    }

    ftime(&last_check);
    while (1) {
        usleep(INTERVAL * 1000000);
        ftime(&current_time);
        if (current_time.time - last_check.time >= INTERVAL) {
            curl_global_cleanup();
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();

            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, URL);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
                curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
                curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

                res = curl_easy_perform(curl);

                if (res == CURLE_OK) {
                    log("Site is up");
                } else {
                    log("Site is down");
                }

                curl_easy_cleanup(curl);
            }

            ftime(&last_check);
        }
    }

    return 0;
}