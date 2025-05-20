//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_URL_LENGTH 256

typedef struct {
    char url[MAX_URL_LENGTH];
    int status;
} WebsiteStatus;

WebsiteStatus websiteStatuses[MAX_URLS];
int numUrls = 0;

size_t handle_response(char *ptr, size_t size, size_t nmemb, void *userdata) {
    int status;
    sscanf(ptr, "HTTP/1.%*d %d", &status);
    ((WebsiteStatus *) userdata)->status = status;
    return size * nmemb;
}

void check_websites() {
    CURL *curl;
    CURLcode result;
    for (int i = 0; i < numUrls; i++) {
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, websiteStatuses[i].url);
            curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &(websiteStatuses[i]));
            result = curl_easy_perform(curl);
            if (result != CURLE_OK) {
                printf("Error checking website %s: %s\n", websiteStatuses[i].url, curl_easy_strerror(result));
            }
            curl_easy_cleanup(curl);
        } else {
            printf("Error initializing CURL for website %s\n", websiteStatuses[i].url);
        }
    }
}

void print_statuses() {
    printf("Website statuses:\n");
    for (int i = 0; i < numUrls; i++) {
        printf("%s: %d\n", websiteStatuses[i].url, websiteStatuses[i].status);
    }
    printf("\n");
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a list of website URLs to monitor (up to %d; enter 'done' to finish):\n", MAX_URLS);
    while (numUrls < MAX_URLS) {
        printf("Website %d: ", numUrls + 1);
        scanf("%s", url);
        if (strcmp(url, "done") == 0) {
            break;
        }
        strcpy(websiteStatuses[numUrls].url, url);
        websiteStatuses[numUrls].status = -1;
        numUrls++;
    }
    printf("Monitoring %d website(s):\n", numUrls);
    for (int i = 0; i < numUrls; i++) {
        printf("%s\n", websiteStatuses[i].url);
    }
    printf("\n");
    while (1) {
        check_websites();
        print_statuses();
        time_t t = time(NULL);
        struct tm *time_info = localtime(&t);
        char buffer[26];
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", time_info);
        printf("Last checked at %s. Sleeping for 10 seconds...\n", buffer);
        printf("\n");
        sleep(10);
    }
    return 0;
}