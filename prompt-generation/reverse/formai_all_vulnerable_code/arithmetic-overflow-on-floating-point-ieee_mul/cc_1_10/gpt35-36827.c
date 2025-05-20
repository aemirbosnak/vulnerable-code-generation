//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
// This is a Website Uptime Monitor program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// This is the URL that we will be monitoring
#define URL "http://example.com"

// This is the minimum response time in milliseconds
#define MIN_RESPONSE_TIME 5000

// This is the maximum response time in milliseconds
#define MAX_RESPONSE_TIME 10000

// This is the amount of time in seconds to wait between checks
#define CHECK_INTERVAL 60

// This is the user agent string sent with the request
const char *USER_AGENT = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3";

// This is the curl handle used to make requests
CURL *curl = NULL;

// This function is called by curl to handle responses
static size_t curl_callback(void *ptr, size_t size, size_t nmemb, void *data) {
    return size * nmemb;
}

// This function checks the website for uptime
int check_website() {
    CURLcode res;
    curl_easy_reset(curl);

    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, USER_AGENT);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "Error performing curl request: %s\n", curl_easy_strerror(res));
        return 0;
    }

    long response_code;
    double elapsed;

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);

    if (response_code != 200) {
        fprintf(stderr, "Error: HTTP response code %ld\n", response_code);
        return 0;
    }

    if (elapsed * 1000 < MIN_RESPONSE_TIME) {
        fprintf(stderr, "Error: Response time for %s was less than %dms\n", URL, MIN_RESPONSE_TIME);
        return 0;
    }

    if (elapsed * 1000 > MAX_RESPONSE_TIME) {
        fprintf(stderr, "Error: Response time for %s was greater than %dms\n", URL, MAX_RESPONSE_TIME);
        return 0;
    }

    return 1;
}

int main() {
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Error initializing curl\n");
        return EXIT_FAILURE;
    }

    while (1) {
        if (check_website()) {
            printf("%s is up\n", URL);
        } else {
            printf("%s is down\n", URL);
        }

        sleep(CHECK_INTERVAL);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return EXIT_SUCCESS;
}