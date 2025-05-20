//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <time.h>

#define URL "https://www.example.com"

double getTimeDiff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    return size * nmemb;
}

bool isSiteUp() {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            return false;
        }
        curl_easy_cleanup(curl);
        return true;
    }
    return false;
}

int main() {
    printf("Website Uptime Monitor\n\n");

    long maxTries = 5000;
    long timeBetweenTries = 60;
    long timeBetweenLogs = 600;
    long totalTries = 0;
    long totalSuccessfulTries = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    while (totalTries < maxTries) {
        if (isSiteUp()) {
            totalSuccessfulTries++;
            printf("[SUCCESS] ");
        } else {
            printf("[FAIL] ");
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("Time: %.2f seconds | Successful tries: %d | Total tries: %d\n",
                getTimeDiff(start, end), totalSuccessfulTries, ++totalTries);

        if (totalTries % (timeBetweenLogs / timeBetweenTries) == 0) {
            printf("\n** Logging intervals **\n");
            printf("Time: %.2f seconds | Successful tries: %d | Total tries: %d\n",
                   getTimeDiff(start, end), totalSuccessfulTries, totalTries);
        }
        sleep(timeBetweenTries);
    }

    printf("\nWebsite monitoring finished\n");
    printf("Total time: %.2f seconds | Successful tries: %d | Total tries: %d\n\n",
           getTimeDiff(start, end), totalSuccessfulTries, totalTries);
    return 0;
}