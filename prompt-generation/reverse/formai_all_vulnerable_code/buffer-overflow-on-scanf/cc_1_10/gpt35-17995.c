//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LEN 200
#define MAX_RESPONSE_LEN 500

typedef struct website {
    char url[MAX_URL_LEN];
    int num_failures;
} Website;

Website *init_websites(int num_websites) {
    Website *websites = malloc(num_websites * sizeof(Website));
    for(int i = 0; i < num_websites; i++) {
        printf("Enter URL for website %d: ", i+1);
        scanf("%s", websites[i].url);
        websites[i].num_failures = 0;
    }
    return websites;
}

void monitor_website(Website *website) {
    CURL *curl;
    CURLcode res;
    char response[MAX_RESPONSE_LEN];
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            website->num_failures++;
            printf("%s failed to respond. Number of failures: %d\n", website->url, website->num_failures);
        }
        else {
            printf("%s responded with status code %d\n", website->url, res);
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    int num_websites;
    printf("Enter number of websites to monitor: ");
    scanf("%d", &num_websites);
    Website *websites = init_websites(num_websites);

    while(1) {
        for(int i = 0; i < num_websites; i++) {
            monitor_website(&websites[i]);
        }
        sleep(60); // check every minute
    }

    return 0;
}