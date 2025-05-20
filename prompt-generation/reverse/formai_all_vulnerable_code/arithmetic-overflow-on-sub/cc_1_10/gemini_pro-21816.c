//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Ada Lovelace
// An Ada Lovelace-inspired C Website Uptime Monitor

// Ada Lovelace, the world's first computer programmer, deserves a fitting tribute.
// This website uptime monitor is a humble homage to her pioneering spirit.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

// Constants
#define MAX_URL_LENGTH 256
#define MAX_CHECK_INTERVAL 3600 // 1 hour

// Data structures
typedef struct {
    char url[MAX_URL_LENGTH];
    time_t last_check;
    int status_code;
} Website;

// Function prototypes
void check_website(Website *website);
void print_report(Website *website);

// Main function
int main(int argc, char **argv) {
    // Initialize website data
    Website website;
    strcpy(website.url, "https://example.com");
    website.last_check = 0;
    website.status_code = -1;

    // Check website uptime every 30 minutes
    while (1) {
        // Check website
        check_website(&website);

        // Print report
        print_report(&website);

        // Sleep for 30 minutes
        sleep(1800);
    }

    return 0;
}

// Function to check website uptime
void check_website(Website *website) {
    // Get current time
    time_t now = time(NULL);

    // Check if it's time to check the website
    if (now - website->last_check > MAX_CHECK_INTERVAL) {
        // Send HTTP request to website
        CURL *curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, website->url);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
            curl_easy_perform(curl);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &website->status_code);
            curl_easy_cleanup(curl);
        }

        // Update last check time
        website->last_check = now;
    }
}

// Function to print report
void print_report(Website *website) {
    printf("Website: %s\n", website->url);
    printf("Last check: %s\n", ctime(&website->last_check));
    printf("Status code: %d\n\n", website->status_code);
}