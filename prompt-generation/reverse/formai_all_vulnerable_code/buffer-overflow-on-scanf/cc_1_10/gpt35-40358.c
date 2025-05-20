//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#define INTERVAL 120     // check interval in seconds
#define MAX_URLS 10      // maximum number of URLs to monitor
#define MAX_LENGTH 1024  // maximum length of URL

int num_urls = 0;        // number of URLs added
char urls[MAX_URLS][MAX_LENGTH];  // URLs array

// callback function to write curl output to null
size_t write_null(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

// main monitor function
void monitor() {
    CURL *curl_handle;
    CURLcode res;
    int i;

    // loop through URLs and check their status
    for (i = 0; i < num_urls; i++) {
        curl_handle = curl_easy_init();
        if (curl_handle) {
            curl_easy_setopt(curl_handle, CURLOPT_URL, urls[i]);
            curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);
            curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 5L);
            curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_null);
            res = curl_easy_perform(curl_handle);
            if (res != CURLE_OK) {
                printf("%s is down!\n", urls[i]);
            }
            curl_easy_cleanup(curl_handle);
        }
    }
}

// function to add URL to URLs array
void add_url(char *url) {
    if (num_urls < MAX_URLS) {
        strcpy(urls[num_urls], url);
        num_urls++;
    } else {
        printf("Error: Maximum number of URLs reached!\n");
    }
}

int main() {
    char url[MAX_LENGTH];
    int i;

    printf("Welcome to the Website Uptime Monitor!\n");
    printf("Enter URLs to monitor, one at a time.\n");
    printf("Type 'done' when finished.\n");

    // loop to add URLs
    for (i = 1; i <= MAX_URLS; i++) {
        printf("URL %d: ", i);
        scanf("%s", url);
        if (strcmp(url, "done") == 0) {
            break;
        }
        add_url(url);
    }

    // main monitoring loop
    while (1) {
        monitor();
        printf("Waiting %d seconds...\n", INTERVAL);
        sleep(INTERVAL);
    }

    return 0;
}