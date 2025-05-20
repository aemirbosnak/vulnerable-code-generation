//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 500
#define MAX_RESPONSE_LENGTH 5000

// Function to check URL connectivity and status
int check_status(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        if(res == CURLE_OK && response_code == 200) {
            return 1;   // Return 1 if URL is reachable and returns 200 status code
        }
    }
    return 0;   // Return 0 if there is an error or the URL is unreachable or any other status code except 200
}

int main() {
    char urls[10][MAX_URL_LENGTH];  // Array of URLs to monitor
    int num_urls, i;
    printf("Enter the number of URLs to monitor (maximum 10): ");
    scanf("%d", &num_urls);
    printf("Enter the URLs to monitor:\n");
    for(i = 0; i < num_urls; i++) {
        scanf("%s", urls[i]);
    }

    while(1) {  // Infinite loop to keep monitoring the URLs
        printf("\nMonitoring URLs...\n");
        for(i = 0; i < num_urls; i++) {
            if(check_status(urls[i])) {
                printf("%s is up and running\n", urls[i]);    // Prints if URL is up and running
            }
            else {
                printf("%s is down\n", urls[i]);  // Prints if URL is down
            }
        }
        sleep(60);  // Sleep for 60 seconds before checking again
    }

    return 0;
}