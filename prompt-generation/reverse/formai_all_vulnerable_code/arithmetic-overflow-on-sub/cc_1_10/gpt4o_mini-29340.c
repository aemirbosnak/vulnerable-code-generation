//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define URL "http://example.com"
#define MONITOR_PERIOD 60    // Monitor period in seconds
#define CHECK_INTERVAL 10     // Check interval in seconds
#define NUMBER_OF_CHECKS (MONITOR_PERIOD / CHECK_INTERVAL)  // Total number of checks

// Function to perform an HTTP GET request and check the response code
int check_website_status(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only need the response code
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        
        // If response code is 200, the site is up
        if (res == CURLE_OK && response_code == 200) {
            return 1; // Site is up
        }
    }
    return 0; // Site is down
}

// Function to calculate uptime and downtime
void calculate_uptime_downtime(int checks[], int number_of_checks) {
    int up_count = 0, down_count = 0;

    for (int i = 0; i < number_of_checks; i++) {
        if (checks[i] == 1) {
            up_count++;
        } else {
            down_count++;
        }
    }

    double uptime_percentage = ((double)up_count / number_of_checks) * 100.0;
    double downtime_percentage = ((double)down_count / number_of_checks) * 100.0;

    printf("Uptime: %.2f%%\n", uptime_percentage);
    printf("Downtime: %.2f%%\n", downtime_percentage);
}

int main() {
    int checks[NUMBER_OF_CHECKS];
    memset(checks, 0, sizeof(checks)); // Initialize checks array to zeros
    time_t start_time, end_time;

    start_time = time(NULL);
    printf("Monitoring website: %s\n", URL);
    printf("Monitoring duration: %d seconds\n", MONITOR_PERIOD);

    for (int i = 0; i < NUMBER_OF_CHECKS; i++) {
        checks[i] = check_website_status(URL);
        if (checks[i]) {
            printf("Check %d: Site is UP\n", i + 1);
        } else {
            printf("Check %d: Site is DOWN\n", i + 1);
        }
        sleep(CHECK_INTERVAL);
    }

    end_time = time(NULL);
    printf("Monitoring completed in %ld seconds\n", end_time - start_time);

    calculate_uptime_downtime(checks, NUMBER_OF_CHECKS);

    return 0;
}