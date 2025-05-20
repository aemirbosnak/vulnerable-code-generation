//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syslog.h>
#include <time.h>
#include <curl/curl.h>

#define LOG_FACILITY LOG_DAEMON
#define LOG_LEVEL LOG_INFO
#define WEBSITE "www.example.com"
#define INTERVAL 60
#define MAX_RETRIES 3
#define RETRIES_DELAY 5

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    /* No need to implement this function since we only check status code */
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    int retries = 0;
    int elapsed_retries = 0;
    clock_t start, current;

    openlog("website-monitor", LOG_PID | LOG_PERROR, LOG_FACILITY);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, WEBSITE);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

        while(1) {
            syslog(LOG_INFO, "Checking %s...", WEBSITE);

            start = clock();
            res = curl_easy_perform(curl);

            current = clock();
            double elapsed = (double)(current - start) / CLOCKS_PER_SEC;

            if(res != CURLE_OK) {
                if(retries < MAX_RETRIES) {
                    syslog(LOG_WARNING, "Failed to check %s, status code: %d, retrying in %d seconds...",
                           WEBSITE, res, RETRIES_DELAY);
                    sleep(RETRIES_DELAY);
                    retries++;
                    elapsed_retries += RETRIES_DELAY;
                } else {
                    syslog(LOG_ERR, "Failed to check %s after %d retries, status code: %d, elapsed time: %f seconds",
                           WEBSITE, MAX_RETRIES, res, elapsed + elapsed_retries);
                    exit(EXIT_FAILURE);
                }
            } else {
                syslog(LOG_INFO, "Successfully checked %s in %f seconds", WEBSITE, elapsed);
                retries = 0;
                elapsed_retries = 0;
            }

            sleep(INTERVAL);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    closelog();
    return EXIT_SUCCESS;
}