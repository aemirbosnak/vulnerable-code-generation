//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function to check if a website is up or down
int check_website(char* url) {
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            printf("Website is up!\n");
            return 1;
        } else {
            printf("Website is down!\n");
            return 0;
        }
    } else {
        printf("Error initializing curl.\n");
        return 0;
    }
}

// Function to get user input for website URL and check interval
void get_input() {
    char url[100];
    int interval;
    printf("Enter website URL: ");
    scanf("%s", url);
    printf("Enter check interval in seconds: ");
    scanf("%d", &interval);
    while(1) {
        int result = check_website(url);
        if(result == 0) {
            printf("Website is down. Retrying in %d seconds...\n", interval);
        }
        sleep(interval);
    }
}

int main() {
    get_input();
    return 0;
}