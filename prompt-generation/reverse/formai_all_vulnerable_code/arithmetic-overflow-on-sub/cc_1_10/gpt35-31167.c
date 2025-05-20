//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://speedtest.tele2.net/100MB.zip"

// Function that will be called by curl to write downloaded data
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    double speed;
    clock_t start, end;
    double time_elapsed;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        start = clock(); // Start timer

        res = curl_easy_perform(curl);

        end = clock(); // End timer
        time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;

        if (res == CURLE_OK) {
            // Get the download speed in bits per second
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
            printf("Speed: %.2f Mbps\n", speed / 1000000);

            // Get the time taken to download the file
            printf("Time taken: %.2f seconds\n", time_elapsed);
        } else {
            printf("Error: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}