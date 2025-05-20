//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define TIMEOUT 5
#define CHECK_INTERVAL 5

// Structure to store URL and its status
typedef struct {
    char *url;
    int status;
} URLStatus;

// Function to check the status of a given URL
int check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            curl_easy_cleanup(curl);
            return (response_code >= 200 && response_code < 400) ? 1 : 0;
        } else {
            curl_easy_cleanup(curl);
            return 0; // Indicates error or unreachable
        }
    }
    return 0; // Unable to initialize CURL, indicates error
}

void print_status(const URLStatus *urls, int count) {
    printf("\n--- Website Uptime Status ---\n");
    for (int i = 0; i < count; i++) {
        printf("URL: %s is %s\n", urls[i].url, urls[i].status ? "UP" : "DOWN");
    }
    printf("------------------------------\n");
}

int main() {
    URLStatus urls[MAX_URLS];
    int url_count = 0;

    // Gather URLs from the user
    printf("Welcome to the Exciting Website Uptime Monitor!\n");
    printf("You can monitor up to %d websites. Type 'done' when you’re finished entering URLs.\n", MAX_URLS);

    while (url_count < MAX_URLS) {
        char input[256];
        printf("Enter URL %d: ", url_count + 1);
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break; // Break the loop on 'done'
        }
        urls[url_count].url = strdup(input); // Allocate memory for the URL
        urls[url_count].status = -1; // Initial status unknown
        url_count++;
    }

    // Monitoring loop
    printf("\nStarting to monitor the websites every %d seconds...\n", CHECK_INTERVAL);
    while (1) {
        for (int i = 0; i < url_count; i++) {
            urls[i].status = check_url(urls[i].url);
        }
        print_status(urls, url_count);
        sleep(CHECK_INTERVAL);
    }

    // Free allocated memory (This will never be reached in this infinite loop)
    for (int i = 0; i < url_count; i++) {
        free(urls[i].url);
    }

    return 0;
}