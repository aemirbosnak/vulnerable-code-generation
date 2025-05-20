//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"

void log_uptime(const char *url, int status_code) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        fprintf(file, "URL: %s | Status Code: %d\n", url, status_code);
        fclose(file);
    } else {
        printf("Could not open log file for writing!\n");
    }
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize CURL.\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body, just the response code.
    res = curl_easy_perform(curl);
    
    if (res != CURLE_OK) {
        fprintf(stderr, "Curl error: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return -1;
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return (int)response_code;
}

int main() {
    char url[MAX_URL_LENGTH];
    int check_interval;

    printf("🌟 Welcome to the Uptime Wizard! ✨\n");
    printf("Please enter the URL you would like to monitor (example: http://example.com): ");
    scanf("%s", url);

    printf("🎩 How often would you like to check the website (in seconds)? ");
    scanf("%d", &check_interval);

    printf("\n👁️‍🗨️ Monitoring the website: %s every %d seconds...\n", url, check_interval);

    while (1) {
        int status_code = check_website(url);
        if (status_code >= 0) {
            printf("🏰 Status of %s: %d\n", url, status_code);
            log_uptime(url, status_code);
        } else {
            printf("🔮 Trouble reaching the castle at %s. Status unknown!\n", url);
        }

        printf("✨ Sleeping for %d seconds... 💤\n", check_interval);
        sleep(check_interval);
    }

    return 0; // The end of our marvelous journey
}