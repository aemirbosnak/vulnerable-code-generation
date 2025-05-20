//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100
#define TIMEOUT 5

typedef struct {
    char *url;
    int status;
    char *last_checked;
} Website;

Website websites[MAX_URLS];
int website_count = 0;

void log_status(Website *site) {
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline character
    printf("[%s] %s - Status: %d\n", time_str, site->url, site->status);
}

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data) {
    return size * nmemb; // Ignore the data received, just check if it succeeded
}

void check_website(Website *site) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        
        res = curl_easy_perform(curl);
        site->status = (res == CURLE_OK) ? 200 : 404; // Simplified: treat anything other than CURLE_OK as 404
        
        log_status(site);
        
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize cURL for: %s\n", site->url);
    }
}

void load_websites_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (website_count < MAX_URLS && fscanf(file, "%ms", &websites[website_count].url) == 1) {
        websites[website_count].status = 0; // Unknown status initially
        websites[website_count].last_checked = NULL;
        website_count++;
    }

    fclose(file);
}

void free_websites() {
    for (int i = 0; i < website_count; i++) {
        free(websites[i].url);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename_with_urls>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_websites_from_file(argv[1]);

    while (1) {
        printf("\nChecking websites...\n");
        for (int i = 0; i < website_count; i++) {
            check_website(&websites[i]);
            sleep(1); // Sleep to avoid overwhelming the server
        }
        sleep(30); // Run the check every 30 seconds
    }

    free_websites();
    return EXIT_SUCCESS;
}