//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URLS 100
#define TIMEOUT 5
#define MAX_LOGS 100

typedef struct {
    char url[256];
    int status;
    char last_checked[20];
} WebsiteStatus;

WebsiteStatus websiteStatus[MAX_URLS];
int url_count = 0;

void log_status(const char *url, int status) {
    FILE *log_file = fopen("uptime_log.txt", "a");
    if (log_file) {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(websiteStatus[url_count - 1].last_checked, sizeof(websiteStatus[url_count - 1].last_checked), "%Y-%m-%d %H:%M:%S", tm_info);
        fprintf(log_file, "URL: %s | Status: %d | Checked at: %s\n", url, status, websiteStatus[url_count - 1].last_checked);
        fclose(log_file);
    }
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    int status_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only need the headers
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            status_code = -1; // Indicates an error occurred
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return status_code;
}

void add_website(const char *url) {
    if (url_count < MAX_URLS) {
        strcpy(websiteStatus[url_count].url, url);
        websiteStatus[url_count].status = 0; // Initial status
        url_count++;
    } else {
        fprintf(stderr, "Maximum URL limit reached.\n");
    }
}

void monitor_websites() {
    for (int i = 0; i < url_count; i++) {
        websiteStatus[i].status = check_website(websiteStatus[i].url);
        log_status(websiteStatus[i].url, websiteStatus[i].status);
    }
}

void print_menu() {
    printf("Website Uptime Monitor\n");
    printf("======================\n");
    printf("1. Add URL\n");
    printf("2. Monitor URLs\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char url[256];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL to monitor: ");
                scanf("%s", url);
                add_website(url);
                printf("Added: %s\n", url);
                break;
            case 2:
                monitor_websites();
                printf("Monitoring completed.\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}