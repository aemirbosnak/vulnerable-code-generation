//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h> // Include the CURL library

#define URL_LENGTH 128 // Specify the maximum URL length that can be monitored
#define TIMEOUT_MS 1000 // Specify the maximum time to wait for response in milliseconds
#define SLEEP_MS 5000 // Specify the time interval between monitor checks in milliseconds

// Define the function to perform HTTP GET request to the given URL
static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

// Define the function to print the current time
void print_time() {
    time_t current_time;
    char *time_string;
    current_time = time(NULL);
    time_string = ctime(&current_time);
    time_string[strlen(time_string)-1] = '\0'; // Remove the trailing newline character
    printf("[%s] ", time_string);
}

// Define the recursive function to monitor the uptime of the website
void monitor_website(char *url) {
    CURL *curl;
    CURLcode res;
    char error_buffer[CURL_ERROR_SIZE];
    curl = curl_easy_init();
    if(curl) {
        print_time();
        printf("Attempting to connect to %s...\n", url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, TIMEOUT_MS); // Set the maximum time to wait for response
        curl_easy_setopt(curl, CURLOPT_URL, url); // Set the URL to connect to
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // Set the write function to ignore the response
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer); // Set the error buffer to store errors
        res = curl_easy_perform(curl); // Perform the HTTP GET request
        curl_easy_cleanup(curl);
        if (res == CURLE_OK) { // If the request was successful
            print_time();
            printf("%s is up!\n", url);
            sleep(SLEEP_MS); // Wait for the specified interval before making another check
            monitor_website(url); // Make another check recursively
        } else { // If the request failed
            print_time();
            printf("%s is down!\n", url);
            printf("%s\n", error_buffer);
            sleep(SLEEP_MS); // Wait for the specified interval before making another check
            monitor_website(url); // Make another check recursively
        }
    }
}

// Define the main function to prompt the user for input and start the monitor
int main() {
    char url[URL_LENGTH];
    printf("Enter the website URL to monitor: ");
    scanf("%s", url);
    monitor_website(url);
    return 0;
}