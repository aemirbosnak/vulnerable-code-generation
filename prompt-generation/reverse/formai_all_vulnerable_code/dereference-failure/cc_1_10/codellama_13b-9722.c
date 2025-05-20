//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
/*
 * Website Uptime Monitor
 *
 * This program monitors the uptime of a website and sends an alert
 * when it goes down.
 *
 * Usage: ./website_uptime_monitor <website_url>
 *
 * Example: ./website_uptime_monitor https://www.example.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_TIME_LEN 32

int main(int argc, char **argv) {
    char website_url[MAX_URL_LEN];
    char time_str[MAX_TIME_LEN];
    CURL *curl;
    CURLcode res;
    long response_code;

    if (argc != 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    strncpy(website_url, argv[1], MAX_URL_LEN);

    curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize cURL\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, website_url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

    while (1) {
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("Failed to perform cURL request\n");
            return 1;
        }

        res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        if (res != CURLE_OK) {
            printf("Failed to get response code\n");
            return 1;
        }

        if (response_code != 200) {
            printf("Website is down\n");
            break;
        }

        time_t current_time;
        time(&current_time);
        strftime(time_str, MAX_TIME_LEN, "%F %T", localtime(&current_time));
        printf("Website is up, last checked at %s\n", time_str);

        sleep(60); // check again in 60 seconds
    }

    curl_easy_cleanup(curl);
    return 0;
}