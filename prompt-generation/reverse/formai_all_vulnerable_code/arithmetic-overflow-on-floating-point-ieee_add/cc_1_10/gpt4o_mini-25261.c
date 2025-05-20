//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// Function to check website status
int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set timeout for connection
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK && (response_code >= 200 && response_code < 400)) {
            return 1; // Website is up
        } else {
            return 0; // Website is down
        }
    }
    return 0;
}

// Function to print statistics
void print_statistics(int up_count, int down_count, int total_checks, double avg_response_time) {
    printf("\n--- Website Uptime Statistics ---\n");
    printf("Total Checks: %d\n", total_checks);
    printf("Up Time: %d\n", up_count);
    printf("Down Time: %d\n", down_count);
    printf("Uptime Percentage: %.2f%%\n", (double) up_count / total_checks * 100);
    printf("Average Response Time: %.2f seconds\n", avg_response_time);
}

int main() {
    const char *url = "http://example.com"; // Replace with a website of your choice
    int up_count = 0, down_count = 0;
    int checks = 0;
    double total_response_time = 0.0;
    time_t start_time, end_time;

    printf("Starting Website Uptime Monitor for %s\n", url);

    while (1) {
        time(&start_time);
        if (check_website(url)) {
            up_count++;
            printf("[%ld] Website is UP\n", start_time);
        } else {
            down_count++;
            printf("[%ld] Website is DOWN\n", start_time);
        }
        time(&end_time);

        double response_time = difftime(end_time, start_time);
        total_response_time += response_time;
        checks++;

        // Print statistics every 10 checks
        if (checks % 10 == 0) {
            print_statistics(up_count, down_count, checks, total_response_time / checks);
        }

        sleep(5); // Check the website every 5 seconds
    }

    return 0;
}