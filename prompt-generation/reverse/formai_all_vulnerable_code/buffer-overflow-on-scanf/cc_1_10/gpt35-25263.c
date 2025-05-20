//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
 
int main(int argc, char **argv)
{
    char *url;
    int timeout;
    CURL *curl;
 
    // Prompt user for URL and timeout
    printf("Enter the URL to monitor: ");
    scanf("%s", url);
    printf("Enter the timeout (in seconds): ");
    scanf("%d", &timeout);
 
    // Initialize curl
    curl = curl_easy_init();
    if (!curl) {
        printf("Error: could not initialize curl.\n");
        exit(EXIT_FAILURE);
    }
 
    // Set curl options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
 
    // Perform the request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("Error: could not perform the request (%s).\n", curl_easy_strerror(res));
        exit(EXIT_FAILURE);
    }
 
    // Check the HTTP response code
    long http_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        printf("Warning: returned HTTP code is %ld.\n", http_code);
    } else {
        printf("Success: website is up.\n");
    }
 
    // Cleanup curl
    curl_easy_cleanup(curl);
 
    return EXIT_SUCCESS;
}