//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 4096

// Function to perform the HTTP GET request
int check_website_status(const char *url)
{
    CURL *curl;
    CURLcode res;
    long response_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We do not need the body, just the status
        res = curl_easy_perform(curl);
        
        // Check for errors in the request
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 0; // Website is down or error occurred
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        
        // Check if the response code is successful
        if(response_code >= 200 && response_code < 400) {
            return 1; // Website is up
        }
    }
    
    curl_global_cleanup();
    return 0; // Website is down
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    char log_file[MAX_URL_LENGTH];
    
    // Prepare log file name
    snprintf(log_file, sizeof(log_file), "uptime_monitor_log.txt");

    FILE *log_fp = fopen(log_file, "a");
    if(log_fp == NULL) {
        perror("Failed to open log file");
        return EXIT_FAILURE;
    }

    time_t current_time;
    struct tm *tm_info;

    printf("Monitoring website: %s\n", url);
    
    while(1) {
        int status = check_website_status(url);
        
        // Get current time for logging
        time(&current_time);
        tm_info = localtime(&current_time);
        
        // Log to console and to file
        if(status) {
            printf("[%04d-%02d-%02d %02d:%02d:%02d] Website is UP\n",
                   tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
                   tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
            fprintf(log_fp, "[%04d-%02d-%02d %02d:%02d:%02d] Website is UP\n",
                    tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
                    tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
        } else {
            printf("[%04d-%02d-%02d %02d:%02d:%02d] Website is DOWN\n",
                   tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
                   tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
            fprintf(log_fp, "[%04d-%02d-%02d %02d:%02d:%02d] Website is DOWN\n",
                    tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
                    tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
        }

        fflush(log_fp);
        
        // Sleep for 10 seconds before the next check
        sleep(10);
    }

    fclose(log_fp);
    return EXIT_SUCCESS;
}