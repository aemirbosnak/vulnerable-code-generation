//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 50
#define MAX_CHECKS 10

/* Struct to hold information about each check */
typedef struct Check {
    char url[MAX_URL_LENGTH];   // URL to check
    int interval;               // Interval in seconds between checks
    time_t last_checked;        // Last time the check was performed
} Check;

void check_url(char* url) {
    CURL* curl = curl_easy_init();      // Initialize curl
    curl_easy_setopt(curl, CURLOPT_URL, url);   // Set the URL
    CURLcode res = curl_easy_perform(curl);    // Perform the check
    if(res != CURLE_OK) {   // If there was an error
        // Print error message
        printf("Error: %s\n", curl_easy_strerror(res)); 
        // TODO: Send an alert
    }
    curl_easy_cleanup(curl);    // Clean up curl
}

int main() {
    // Initialize checks
    Check checks[MAX_CHECKS] = { 
        {"https://www.google.com/", 60, 0},
        {"https://www.amazon.com/", 120, 0}
    };
    int num_checks = 2;

    // Loop indefinitely
    while(1) {
        
        // Perform each check if it's time
        for(int i = 0; i < num_checks; i++) {
            Check* check = &checks[i];
            if(time(NULL) - check->last_checked >= check->interval) {
                check_url(check->url);
                check->last_checked = time(NULL);
            }
        }
        
        // Sleep for 1 second before checking again
        sleep(1);
    }
    return 0;
}