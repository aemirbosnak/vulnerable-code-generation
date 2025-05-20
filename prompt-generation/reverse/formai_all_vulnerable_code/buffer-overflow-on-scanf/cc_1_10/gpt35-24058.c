//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h> // Standard Input/Output library
#include <stdlib.h> // Standard library for dynamic memory allocation
#include <stdbool.h> // Boolean type library
#include <curl/curl.h> // Library for transfer of files over a network from a URL syntax

#define MAX_URL_LENGTH 100 // Maximum length of URL
#define MAX_RETRY_INTERVAL 1800 // Maximum interval (in seconds) to retry checking the URL status

// Struct for storing the URL and uptime status
typedef struct {
    char url[MAX_URL_LENGTH];
    bool isUp;
} UrlData;

// Function for checking the status of the specified URL
bool checkUrlStatus(char *url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        // Set URL to check
        curl_easy_setopt(curl, CURLOPT_URL, url);
        // Follow redirections
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        // Send HTTP request
        res = curl_easy_perform(curl);
        // Check response code
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) {
                // Website is up
                return true;
            }
        }
        // Close the connection
        curl_easy_cleanup(curl);
    }
    // Website is down
    return false;
}

int main() {
    UrlData *urlList = (UrlData *) malloc(sizeof(UrlData)); // Dynamic memory allocation for storing URL data
    int numUrls = 0; // Number of URLs added
    char urlInput[MAX_URL_LENGTH];
    bool isDone = false;
    int retryInterval = 10; // Interval (in seconds) to retry checking the URL status
    int currentRetryInterval = 0; // Current interval (in seconds) to retry checking the URL status
    // Loop for continuously checking the status of added URLs
    while(!isDone) {
        printf("Enter URL to monitor (or 'q' to quit): ");
        scanf("%s", urlInput);
        if(strcmp(urlInput, "q") == 0) {
            isDone = true;
            break;
        }
        // Add URL to the list
        numUrls++;
        urlList = (UrlData *) realloc(urlList, numUrls * sizeof(UrlData));
        strcpy(urlList[numUrls - 1].url, urlInput);
        urlList[numUrls - 1].isUp = checkUrlStatus(urlInput);
    }
    // Loop for continuously checking the status of added URLs
    while(!isDone) {
        // Loop through all added URLs and check their status
        for(int i = 0; i < numUrls; i++) {
            urlList[i].isUp = checkUrlStatus(urlList[i].url);
            // Print status message for the URL
            if(urlList[i].isUp) {
                printf("%s is up and running!\n", urlList[i].url);
            } else {
                printf("%s is down! Trying again in %d seconds...\n", urlList[i].url, retryInterval);
            }
        }
        // Delay before checking again
        currentRetryInterval += retryInterval;
        if(currentRetryInterval > MAX_RETRY_INTERVAL) {
            currentRetryInterval = MAX_RETRY_INTERVAL;
        }
        printf("Waiting %d seconds to check again...\n\n", currentRetryInterval);
        sleep(currentRetryInterval); // Pause execution for currentRetryInterval seconds
    }
    free(urlList); // Release memory allocation
    return 0;
}