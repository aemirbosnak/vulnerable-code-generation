//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define TIME_INTERVAL 10 // Interval between checks in seconds

void log_status(const char *url, const char *status) {
    FILE *log_file = fopen("uptime_log.txt", "a+");
    if (log_file != NULL) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s] %s - %s\n", ctime(&now), url, status);
        fclose(log_file);
    }
}

int check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don’t need body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // Timeout after 5 seconds

        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        
        curl_easy_cleanup(curl);
        return response_code == 200; // Return true if the response is 200 OK
    }
    return 0; // Return false if curl failed to initialize
}

void monitor_websites(char urls[MAX_URLS][256], int url_count) {
    while(1) {
        for(int i = 0; i < url_count; i++) {
            printf("Checking %s...\n", urls[i]);
            if (check_url(urls[i])) {
                printf("Status: %s is UP\n", urls[i]);
                log_status(urls[i], "UP");
            } else {
                printf("Status: %s is DOWN\n", urls[i]);
                log_status(urls[i], "DOWN");
            }
        }
        sleep(TIME_INTERVAL);
    }
}

int main() {
    char urls[MAX_URLS][256];
    int url_count = 0;

    printf("Website Uptime Monitor\n");
    printf("Enter up to %d URLs (type 'done' to finish):\n", MAX_URLS);
    
    while (url_count < MAX_URLS) {
        char input[256];
        printf("URL [%d]: ", url_count + 1);
        scanf("%s", input);
        
        if (strcmp(input, "done") == 0) {
            break;
        }
        strncpy(urls[url_count], input, 255);
        urls[url_count][255] = '\0'; // Ensuring null termination
        url_count++;
    }

    printf("Starting monitor for %d websites...\n", url_count);
    monitor_websites(urls, url_count);

    return 0;
}