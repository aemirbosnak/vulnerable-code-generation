//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include<stdio.h>
#include<sys/time.h>
#include<curl/curl.h>

// Define the URL to hit to test connection speeds
#define URL "http://speedtest.wdc01.softlayer.com/downloads/test10.zip"

// Define the amount of data to download
#define DATA_SIZE (1024*1024*10)

// Define the amount of time to run the test
#define TEST_TIME 10

// Define variables to hold statistics
double total_time, download_speed;

// Callback function for CURL to write downloaded data
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{ 
    return size * nmemb;
}

int main()
{
    // Initialize CURL
    CURL *curl = curl_easy_init();

    // Set URL to test speed
    curl_easy_setopt(curl, CURLOPT_URL, URL);

    // Set CURLOPT_WRITEFUNCTION to write_callback
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // Disable output to stdout
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

    // Set timeout to 10 seconds
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TEST_TIME);

    // Define variables to hold time data
    struct timeval start_time, end_time;

    // Start timer
    gettimeofday(&start_time, NULL);

    // Download data
    CURLcode result = curl_easy_perform(curl);

    // End timer
    gettimeofday(&end_time, NULL);

    // Calculate total time and download speed
    total_time = ((end_time.tv_sec - start_time.tv_sec) * 1000 + (double)(end_time.tv_usec - start_time.tv_usec) / 1000) / 1000;
    download_speed = DATA_SIZE / total_time / 1024 / 1024;

    // Print results
    printf("Download speed: %0.2f MB/s\n", download_speed);

    // Clean up CURL
    curl_easy_cleanup(curl);

    return 0;
}