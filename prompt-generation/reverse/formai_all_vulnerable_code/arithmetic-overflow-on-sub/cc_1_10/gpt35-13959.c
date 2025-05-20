//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define NUM_WEBSITES 3

// Define structure to store website information
struct website {
    char* url;
    int success;
    int total;
    time_t last_checked;
};

typedef struct website Website;

// Initialize websites
Website websites[NUM_WEBSITES] = {
    {"https://www.google.com", 0, 0, 0},
    {"https://www.facebook.com", 0, 0, 0},
    {"https://www.twitter.com", 0, 0, 0}
};

// Function to perform curl request
int perform_request(Website* website) {
    CURL* curl;
    CURLcode res;
    int success = 0;
    
    // Initialize curl
    curl = curl_easy_init();
    
    if(curl) {
        // Set curl options
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Only check if site is available, don't download content
        
        // Send request
        res = curl_easy_perform(curl);
        
        // Check if request was successful
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code >= 200 && response_code < 400) {
                success = 1;
            }
        }
        
        // Clean up curl
        curl_easy_cleanup(curl);
    }
    
    return success;
}

int main() {
    while(1) {
        // Check each website
        for(int i = 0; i < NUM_WEBSITES; i++) {
            if(time(NULL) - websites[i].last_checked >= 60) { // Only check once per minute
                websites[i].last_checked = time(NULL);
                websites[i].total++;
                if(perform_request(&websites[i])) {
                    websites[i].success++;
                    printf("%s is UP\n", websites[i].url);
                } else {
                    printf("%s is DOWN\n", websites[i].url);
                }
            }
        }
    }
    
    return 0;
}