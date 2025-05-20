//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 200
#define MAX_LOG_LENGTH 100

// Define struct for storing URL and its corresponding log file name
struct URL {
    char url[MAX_URL_LENGTH];
    char log[MAX_LOG_LENGTH];
};

// Function to check if a website is up or down
int is_website_up(char* url) {
    CURL *curl = curl_easy_init();
    CURLcode res;

    // Set CURL options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    // Perform the request
    res = curl_easy_perform(curl);

    // Cleanup
    curl_easy_cleanup(curl);

    // If response not equal to CURLE_OK, then website is down
    if (res != CURLE_OK) {
        return 0;
    }

    return 1;
}

// Function to log the status of the website
void log_website_status(char* url, char* log_filename, int is_up) {
    FILE* fp;
    time_t current_time;
    char* c_time_string;

    // Get current time
    current_time = time(NULL);

    // Convert current time to string format
    c_time_string = ctime(&current_time);

    // Check if log file exists, if not create one
    if( access( log_filename, F_OK ) != -1 ) {
        fp = fopen(log_filename, "a");
    } else {
        fp = fopen(log_filename, "w");
    }

    // Write log to file
    if (is_up) {
        fprintf(fp, "[%s] %s is up.\n", c_time_string, url);
    } else {
        fprintf(fp, "[%s] %s is down.\n", c_time_string, url);
    }

    fclose(fp);
}

int main() {
    int num_urls;
    struct URL *urls;

    printf("Enter the number of URLs you want to monitor: ");
    scanf("%d", &num_urls);

    // Allocate memory for array of URLs
    urls = (struct URL*) malloc(num_urls * sizeof(struct URL));

    // Get URLs and log file names from user
    for (int i = 0; i < num_urls; i++) {
        printf("Enter the URL to monitor: ");
        scanf("%s", urls[i].url);
        printf("Enter the log file name for %s: ", urls[i].url);
        scanf("%s", urls[i].log);
    }

    // Infinite loop to keep monitoring the websites
    while(1) {
        for (int i = 0; i < num_urls; i++) {
            // Check if website is up
            int is_up = is_website_up(urls[i].url);

            // Log the status of the website
            log_website_status(urls[i].url, urls[i].log, is_up);
        }

        // Sleep for 5 minutes before checking again
        sleep(300);
    }

    // Free memory allocated for URLs
    free(urls);

    return 0;
}