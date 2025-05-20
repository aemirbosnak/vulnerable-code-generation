//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

// Function prototypes
void check_website_status(void *arg);
size_t write_to_file(void *ptr, size_t size, size_t nmemb, FILE *stream);

int main()
{
    CURL *curl;
    FILE *file;
    char url[50];
    pthread_t thread_id;

    // Get website URL from user input
    printf("Enter website URL: ");
    scanf("%s", url);

    // Open log file for writing
    file = fopen("website_status.log", "w");
    if (file == NULL)
    {
        printf("Error opening log file.\n");
        return 1;
    }

    // Initialize cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL)
    {
        printf("Error initializing cURL.\n");
        return 1;
    }

    // Set cURL options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_file);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Start thread for periodic website checks
    pthread_create(&thread_id, NULL, check_website_status, (void *)curl);

    // Wait for thread to finish
    pthread_join(thread_id, NULL);

    // Clean up
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    fclose(file);

    return 0;
}

// Function to check website status periodically
void check_website_status(void *arg)
{
    CURL *curl = (CURL *)arg;
    struct timespec ts;

    // Set initial delay
    ts.tv_sec = 0;
    ts.tv_nsec = 100000000; // 100 ms

    // Loop indefinitely
    while (1)
    {
        // Check website status
        curl_easy_perform(curl);

        // Wait for specified delay
        nanosleep(&ts, NULL);

        // Adjust delay for next check
        ts.tv_nsec += 5000000; // 5 seconds
    }
}

// Function to write data to log file
size_t write_to_file(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}