//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <time.h>

#define MAX_URLS 100
#define MAX_LEN 256
#define CHECK_INTERVAL 5  // seconds

typedef struct {
    char url[MAX_LEN];
    int is_up;
} UrlStatus;

typedef struct {
    UrlStatus urls[MAX_URLS];
    int count;
} UptimeMonitor;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb; // just discard the data received
}

void check_url(UptimeMonitor *monitor, int index) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, monitor->urls[index].url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            monitor->urls[index].is_up = 0; // URL is down
        } else {
            monitor->urls[index].is_up = 1; // URL is up
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void display_status(UptimeMonitor *monitor) {
    printf("\nWebsite Status:\n");
    printf("================================\n");
    for(int i = 0; i < monitor->count; i++) {
        printf("URL: %-40s Status: %s\n", monitor->urls[i].url, monitor->urls[i].is_up ? "UP" : "DOWN");
    }
    printf("================================\n");
}

int main() {
    UptimeMonitor monitor;
    monitor.count = 0;

    printf("Website Uptime Monitor\n");
    printf("=======================\n");
    printf("Enter the number of URLs to monitor (max %d): ", MAX_URLS);
    scanf("%d", &monitor.count);

    if(monitor.count > MAX_URLS) {
        printf("Exceeded maximum URL limit of %d. Exiting.\n", MAX_URLS);
        return 1;
    }

    // Input URLs
    for(int i = 0; i < monitor.count; i++) {
        printf("Enter URL %d: ", i + 1);
        scanf("%s", monitor.urls[i].url);
        monitor.urls[i].is_up = -1; // Initialize with unknown status
    }

    // Monitor loop
    while(1) {
        for(int i = 0; i < monitor.count; i++) {
            check_url(&monitor, i);
        }
        
        display_status(&monitor);
        sleep(CHECK_INTERVAL);
    }

    return 0;
}