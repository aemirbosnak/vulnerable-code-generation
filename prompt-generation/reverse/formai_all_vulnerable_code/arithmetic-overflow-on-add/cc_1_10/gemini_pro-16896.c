//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>
#include <stdbool.h>

#define NUM_CHECKS 10
#define CHECK_INTERVAL 600  // 10 minutes

typedef struct {
    char *url;
    time_t last_checked;
    int status_code;
    bool is_up;
} website;

// Function to check the status of a website
int check_website(website *site) {
    CURL *curl;
    CURLcode res;
    char error_buffer[CURL_ERROR_SIZE];

    // Initialize the CURL library
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return -1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, site->url);

    // Set the error buffer
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);

    // Set the timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Perform the request
    res = curl_easy_perform(curl);

    // Get the status code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &site->status_code);

    // Check if the request was successful
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", error_buffer);
        site->is_up = false;
    } else {
        site->is_up = (site->status_code == 200);
    }

    // Cleanup the CURL library
    curl_easy_cleanup(curl);

    return 0;
}

// Function to print the status of a website
void print_website_status(website *site) {
    printf("%s: ", site->url);

    if (site->is_up) {
        printf("up (status code: %d)\n", site->status_code);
    } else {
        printf("down (status code: %d)\n", site->status_code);
    }
}

// Main function
int main() {
    // Initialize the array of websites to check
    website websites[] = {
        { "https://www.google.com", 0, 0, false },
        { "https://www.facebook.com", 0, 0, false },
        { "https://www.amazon.com", 0, 0, false },
        { "https://www.microsoft.com", 0, 0, false },
        { "https://www.apple.com", 0, 0, false },
    };

    // Check the websites and print their status
    for (int i = 0; i < NUM_CHECKS; i++) {
        for (int j = 0; j < sizeof(websites) / sizeof(website); j++) {
            if (time(NULL) >= websites[j].last_checked + CHECK_INTERVAL) {
                check_website(&websites[j]);
                websites[j].last_checked = time(NULL);
            }

            print_website_status(&websites[j]);
        }

        // Sleep for the specified interval
        sleep(CHECK_INTERVAL);
    }

    return 0;
}