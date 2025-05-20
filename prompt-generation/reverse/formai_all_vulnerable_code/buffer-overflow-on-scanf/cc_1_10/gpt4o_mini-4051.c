//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define URL_SIZE 256
#define LOG_SIZE 512

// Function to get the current time as a string
const char* get_current_time() {
    time_t now;
    time(&now);
    return ctime(&now);
}

// Function to perform the HTTP request
int check_website(const char* url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
        curl_global_cleanup();

        // Check for successful response
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            return (response_code == 200) ? 1 : 0; // 1 = up, 0 = down
        }
    }
    return 0;
}

// Function to log the status into a file
void log_status(const char* url, int status) {
    FILE *logfile = fopen("uptime_log.txt", "a");
    if (logfile == NULL) {
        perror("Unable to open log file!");
        exit(EXIT_FAILURE);
    }

    fprintf(logfile, "[%s] %s is %s\n", get_current_time(), url, (status) ? "UP" : "DOWN");
    fclose(logfile);
}

// Function to dynamically adjust the checking interval based on user preference
void start_monitoring(const char* url, int interval) {
    while (1) {
        int status = check_website(url);
        log_status(url, status);
        sleep(interval);
    }
}

int main() {
    char url[URL_SIZE];
    int interval;

    // User inputs
    printf("Enter the URL to monitor (including http:// or https://): ");
    fgets(url, URL_SIZE, stdin);
    url[strcspn(url, "\n")] = 0; // Remove new line character

    printf("Enter the checking frequency in seconds (e.g. 5, 10): ");
    scanf("%d", &interval);

    if (interval < 1) {
        printf("Interval should be at least 1 second.\n");
        return EXIT_FAILURE;
    }

    printf("Starting to monitor %s every %d seconds...\n", url, interval);
    
    // Start the uptime monitoring in a dynamic loop
    start_monitoring(url, interval);

    return EXIT_SUCCESS;
}