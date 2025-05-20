//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define URL "http://example.com" // Replace with your target URL
#define CHECK_INTERVAL 10 // Interval between checks in seconds
#define MAX_ATTEMPTS 5 // Maximum attempts for reconnecting
#define OUTPUT_FILE "uptime_log.txt"

void log_status(const char *status);
int check_website(const char *url);
void paranoid_sleep(int seconds);

int main() {
    FILE *fptr = fopen(OUTPUT_FILE, "a");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file for logging\n");
        return EXIT_FAILURE;
    }

    fprintf(fptr, "Starting website uptime monitor for %s - %s\n", URL, ctime(&(time_t){time(NULL)}));
    fclose(fptr);

    int consecutive_down = 0;

    while (1) {
        if (check_website(URL) == 0) {
            fprintf(stderr, "Website is down! Attempting recovery...\n");
            consecutive_down++;

            if (consecutive_down >= MAX_ATTEMPTS) {
                fprintf(stderr, "Maximum attempts reached. Taking further paranoia measures...\n");
                // Additional paranoid measures can be implemented here, e.g., send alerts, change URLs, etc.
                system("echo 'Website is still down!' | mail -s 'Uptime Alert!' your_email@example.com");
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Website is up!\n");
            consecutive_down = 0;
        }

        paranoid_sleep(CHECK_INTERVAL);
    }

    return EXIT_SUCCESS;
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    int status_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            status_code = (http_code == 200) ? 1 : 0;
            if (status_code) {
                log_status("Website is up.");
            } else {
                log_status("Received non-200 response code.");
            }
        } else {
            log_status("Failed to connect.");
            status_code = 0;
        }

        curl_easy_cleanup(curl);
    } else {
        log_status("Failed to initialize curl.");
        status_code = 0;
    }

    curl_global_cleanup();
    return status_code;
}

void log_status(const char *status) {
    FILE *fptr = fopen(OUTPUT_FILE, "a");
    if (fptr) {
        fprintf(fptr, "[%s]: %s\n", ctime(&(time_t){time(NULL)}), status);
        fclose(fptr);
    } else {
        fprintf(stderr, "Error logging status\n");
    }
}

void paranoid_sleep(int seconds) {
    // Add paranoia to sleeping
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds) {
        // Implementing busy-wait to add a layer of paranoia
        for (volatile int i = 0; i < 100000; i++) {
            // Do nothing, just waste time
        }
    }
}