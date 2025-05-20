//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

// Custom data structure to store website uptime data
typedef struct {
    char *url;
    int status_code;
    time_t last_checked;
    int num_checks;
    int num_failures;
} website_uptime_data;

// Function to check the uptime of a website
int check_website_uptime(website_uptime_data *data) {
    CURL *curl;
    CURLcode res;

    // Initialize the cURL session
    curl = curl_easy_init();
    if (!curl) {
        return -1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, data->url);

    // Set the timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Set the user agent
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36");

    // Execute the request
    res = curl_easy_perform(curl);

    // Get the status code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &data->status_code);

    // Cleanup the cURL session
    curl_easy_cleanup(curl);

    // Update the last checked time
    data->last_checked = time(NULL);

    // Increment the number of checks
    data->num_checks++;

    // Check if the request failed
    if (res != CURLE_OK) {
        data->num_failures++;
    }

    return res;
}

// Function to print the website uptime data
void print_website_uptime_data(website_uptime_data *data) {
    printf("Website: %s\n", data->url);
    printf("Status code: %d\n", data->status_code);
    printf("Last checked: %s\n", ctime(&data->last_checked));
    printf("Number of checks: %d\n", data->num_checks);
    printf("Number of failures: %d\n", data->num_failures);
}

// Function to free the website uptime data
void free_website_uptime_data(website_uptime_data *data) {
    free(data->url);
    free(data);
}

// Main function
int main() {
    // Create an array of website uptime data
    website_uptime_data *websites[] = {
        { "https://www.google.com", 0, 0, 0, 0 },
        { "https://www.facebook.com", 0, 0, 0, 0 },
        { "https://www.amazon.com", 0, 0, 0, 0 },
    };

    // Check the uptime of each website
    for (int i = 0; i < sizeof(websites) / sizeof(website_uptime_data *); i++) {
        check_website_uptime(websites[i]);
    }

    // Print the website uptime data
    for (int i = 0; i < sizeof(websites) / sizeof(website_uptime_data *); i++) {
        print_website_uptime_data(websites[i]);
    }

    // Free the website uptime data
    for (int i = 0; i < sizeof(websites) / sizeof(website_uptime_data *); i++) {
        free_website_uptime_data(websites[i]);
    }

    return 0;
}