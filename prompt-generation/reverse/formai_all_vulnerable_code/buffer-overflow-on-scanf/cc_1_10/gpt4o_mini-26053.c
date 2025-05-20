//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define BUFFER_SIZE 256

typedef struct {
    char url[BUFFER_SIZE];
    int status_code;
    time_t last_checked;
} UrlMonitor;

/* Function prototypes */
void initialize_monitoring(UrlMonitor *monitors, int count);
void check_urls(UrlMonitor *monitors, int count);
void report_status(UrlMonitor *monitors, int count);
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data);

/* Main function to run the program */
int main() {
    UrlMonitor monitors[MAX_URLS];
    int url_count;

    printf("Welcome to the Uptime Monitor!\n");
    printf("How many URLs would you like to monitor (max %d)? ", MAX_URLS);
    scanf("%d", &url_count);

    if (url_count < 1 || url_count > MAX_URLS) {
        fprintf(stderr, "Error: Invalid number of URLs specified.\n");
        return EXIT_FAILURE;
    }

    initialize_monitoring(monitors, url_count);
    
    /* Main monitoring loop */
    while (1) {
        check_urls(monitors, url_count);
        report_status(monitors, url_count);
        sleep(60); // Wait for one minute before the next check
    }

    return EXIT_SUCCESS;
}

/* Initialize the monitoring structure with URLs entered by the user */
void initialize_monitoring(UrlMonitor *monitors, int count) {
    char input_url[BUFFER_SIZE];
    for (int i = 0; i < count; ++i) {
        printf("Enter URL #%d to monitor: ", i + 1);
        scanf("%s", input_url);
        snprintf(monitors[i].url, BUFFER_SIZE, "%s", input_url);
        monitors[i].status_code = 0;
        monitors[i].last_checked = time(NULL);
    }
}

/* Check the status of the URLs using libcurl */
void check_urls(UrlMonitor *monitors, int count) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        for (int i = 0; i < count; ++i) {
            curl_easy_setopt(curl, CURLOPT_URL, monitors[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            } else {
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                monitors[i].status_code = response_code;
                monitors[i].last_checked = time(NULL);
            }
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

/* Report the status of monitored URLs */
void report_status(UrlMonitor *monitors, int count) {
    printf("\nUptime Report:\n");
    for (int i = 0; i < count; ++i) {
        printf("URL: %s | Status Code: %d | Last Checked: %s", 
               monitors[i].url, 
               monitors[i].status_code, 
               ctime(&monitors[i].last_checked));
    }
}

/* Callback function for write operations (dummy function) */
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data) {
    return size * nmemb;  // We do not process the response; just discard it.
}