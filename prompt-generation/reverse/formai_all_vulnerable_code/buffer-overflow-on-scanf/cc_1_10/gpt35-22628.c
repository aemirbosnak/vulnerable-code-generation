//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void) {
    CURL *curl;
    CURLcode res;
    char url[100];
    char name[50];
    int interval;

    printf("Welcome to the Website Uptime Monitor!\n");

    while (1) {
        // Get user input for website URL, name, and interval
        printf("\nEnter a website URL: ");
        scanf("%s", url);
        printf("Enter a name for the website: ");
        scanf("%s", name);
        printf("Enter an interval (in seconds) to check the website: ");
        scanf("%d", &interval);

        curl = curl_easy_init();
        if (curl) {
            // Set cURL options for the website URL and timeout
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

            // Make the HTTP request
            res = curl_easy_perform(curl);

            // Check if the request was successful
            if (res == CURLE_OK) {
                printf("\n%s is online and responding!\n", name);
            } else {
                printf("\n%s is offline! Error code: %d\n", name, res);
            }

            // Clean up cURL resources
            curl_easy_cleanup(curl);
        } else {
            printf("\nError initializing cURL!\n");
            exit(EXIT_FAILURE);
        }

        // Wait for the specified interval before checking again
        printf("\nWaiting %d seconds before checking %s again...\n", interval, name);
        sleep(interval);
    }

    return 0;
}