//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define DOWNLOAD_URL "http://ipv4.download.thinkbroadband.com/1Meg.file" // Test file source
#define FILE_SIZE 1048576 // Size in bytes (1 MB)

struct WriteThis {
    const char *data;
    size_t len;
};

// This function will output the download progress
static size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    return realsize;
}

// Function to measure the download speed
void measure_speed() {
    CURL *curl;
    CURLcode res;

    struct WriteThis chunk = {
        .data = NULL,
        .len = 0
    };

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        // Set the URL to download
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        
        // Measure the time taken to download
        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();
        
        // Calculate the time taken
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double speed = (FILE_SIZE / time_taken) / 1024; // KB/s
            printf("Download Speed: %.2f KB/s\n", speed);
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Function to simulate the ping command
void ping_test(const char *hostname) {
    char command[100];
    snprintf(command, sizeof(command), "ping -c 4 %s", hostname);
    printf("Pinging %s...\n", hostname);
    system(command);
}

// Main function
int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This program will measure your download speed and latency.\n");

    // Measure speed
    measure_speed();

    // Measure ping
    ping_test("google.com");

    printf("Speed test complete. Have a great day!\n");
    return 0;
}