//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <time.h>

// The URL to monitor
char url[] = "https://example.com/";

// The timeout in seconds
int timeout = 10;

// The interval between checks in seconds
int interval = 60;

// The number of checks to perform
int count = 10;

// The list of the last few times checks were made.
time_t times[10];

// The result of the last check.
int result = 0;

// Function to get the current time.
time_t get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec;
}

// Function to check the URL and return the result.
int check_url() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (!curl) {
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        return -1;
    }
    return 0;
}

// Function to check the URL and print the result.
void print_result() {
    time_t now = get_time();
    times[0] = now;
    result = check_url();

    if (result == 0) {
        printf("%s: OK\n", ctime(&now));
    } else {
        printf("%s: ERROR\n", ctime(&now));
    }
}

// Function to pause for a number of seconds.
void pause(int seconds) {
    time_t now = get_time();
    while (get_time() < now + seconds) {
        // Do nothing
    }
}

// Main function.
int main() {
    // Initialize the times array.
    for (int i = 1; i < 10; i++) {
        times[i] = 0;
    }

    // Perform the checks.
    for (int i = 0; i < count; i++) {
        print_result();
        pause(interval);
    }

    // Print the summary.
    printf("\nSummary:\n");
    for (int i = 0; i < 10; i++) {
        if (times[i] != 0) {
            printf("Check %d: %s", i + 1, ctime(&times[i]));
            if (result == 0) {
                printf("OK\n");
            } else {
                printf("ERROR\n");
            }
        }
    }

    return 0;
}