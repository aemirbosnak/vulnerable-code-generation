//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URLS 10      // Maximum number of URLs to monitor
#define TIMEOUT 30L      // Timeout in seconds
#define INTERVAL 60      // Monitoring interval in seconds

// Data structure to hold URL and its corresponding status
typedef struct {
    char url[100];
    int status;
} Website;

// Function to monitor a single website
int monitor_website(Website *site) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if (curl) {
        // Set URL to monitor
        curl_easy_setopt(curl, CURLOPT_URL, site->url);

        // Set timeout
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        // Perform the request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            // Connection error
            site->status = 0;
        } else {
            // Get HTTP response code
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

            site->status = http_code;
        }

        // Cleanup
        curl_easy_cleanup(curl);
    } else {
        site->status = -1;   // Error initializing cURL
    }

    return site->status;
}

int main() {
    Website sites[MAX_URLS];   // Array of websites to monitor
    int num_sites = 0;         // Number of websites to monitor
    
    // Ask user for websites to monitor
    printf("Enter number of websites to monitor (max 10): ");
    scanf("%d", &num_sites);

    if (num_sites > MAX_URLS) {
        printf("Maximum number of websites exceeded. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < num_sites; i++) {
        printf("Enter URL %d: ", i + 1);
        scanf("%s", sites[i].url);
        sites[i].status = -1;   // Initialize status to -1 (unknown)
    }

    printf("Starting website uptime monitor...\n");

    while (1) {
        for (int i = 0; i < num_sites; i++) {
            monitor_website(&sites[i]);
            printf("%s: ", sites[i].url);

            if (sites[i].status == -1) {
                printf("Unknown\n");
            } else if (sites[i].status == 0) {
                printf("Connection error\n");
            } else {
                printf("HTTP %d\n", sites[i].status);
            }
        }

        printf("Sleeping for %d seconds...\n", INTERVAL);
        sleep(INTERVAL);
    }

    return 0;
}