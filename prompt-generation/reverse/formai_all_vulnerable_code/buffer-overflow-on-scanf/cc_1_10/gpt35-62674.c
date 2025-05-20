//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

#define URL_LEN 256
#define TIMEOUT 10L

// Function to check website status using curl
bool check_website_status(char* url) {
    CURL* curl;
    CURLcode res;
    bool status = false;
    char errbuf[CURL_ERROR_SIZE];

    curl = curl_easy_init();

    if(curl) {
        // Set URL to check and set timeout
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        // Disable progress bar and error buffer
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);

        // Perform the request and check status code
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            printf("Error: %s\n", errbuf);
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code == 200) {
                status = true;
            }
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    return status;
}

int main() {
    char url[URL_LEN];

    printf("Enter URL to monitor: ");
    scanf("%s", url);

    printf("Monitoring %s...\n", url);

    while(true) {
        if(check_website_status(url)) {
            printf("%s is UP!\n", url);
        } else {
            printf("%s is DOWN :(\n", url);
        }

        // Delay 10 seconds before checking again
        sleep(10);
    }

    return 0;
}