//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#define MAX_URL_LEN 1024
#define MAX_TIMEOUT 30
#define MAX_TRIES 3

//The main function
int main() {

//  Declare the variables
    char url[MAX_URL_LEN];
    int timeout = MAX_TIMEOUT;
    int tries = MAX_TRIES;
    int status = 0;
    CURL *curl;
    CURLcode res;
    
    //Get the URL to monitor
    printf("Enter the URL to monitor: ");
    scanf("%s", url);
    
    //Get the timeout value
    printf("Enter the timeout value (in seconds): ");
    scanf("%d", &timeout);
    
    //Get the number of tries
    printf("Enter the number of tries: ");
    scanf("%d", &tries);
    
    //Initialize the curl object
    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Failed to initialize curl.\n");
        return 1;
    }
    
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, timeout);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 5L);
    
    //Perform the HTTP request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to perform HTTP request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }
    
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
    if (status != 200) {
        printf("The website is down! (HTTP status code: %d)\n", status);
    } else {
        printf("The website is up! (HTTP status code: %d)\n", status);
    }

// Cleanup curl object
    curl_easy_cleanup(curl);
    return 0;
}