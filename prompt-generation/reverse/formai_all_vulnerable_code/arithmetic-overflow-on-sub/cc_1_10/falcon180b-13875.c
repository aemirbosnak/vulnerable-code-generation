//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

// Function to set the timeout for the cURL request
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *file;
    CURLcode res;
    struct timeval start, end;
    double time_taken;

    // Initialize the cURL library
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Set the URL to monitor
    char url[100] = "http://www.example.com";

    // Open the log file for writing
    file = fopen("website_uptime_log.txt", "a+");

    // Initialize the cURL session
    curl = curl_easy_init();

    // Set the cURL options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Perform the cURL request
    res = curl_easy_perform(curl);

    // Get the start and end times for the request
    gettimeofday(&start, NULL);
    gettimeofday(&end, NULL);

    // Calculate the time taken for the request
    time_taken = (end.tv_sec - start.tv_sec) * 1000.0;
    time_taken += (end.tv_usec - start.tv_usec) / 1000.0;

    // Print the result to the log file
    fprintf(file, "Request took %.2f ms\n", time_taken);

    // Close the log file
    fclose(file);

    // Clean up the cURL session
    curl_easy_cleanup(curl);

    // Clean up the cURL library
    curl_global_cleanup();

    return 0;
}