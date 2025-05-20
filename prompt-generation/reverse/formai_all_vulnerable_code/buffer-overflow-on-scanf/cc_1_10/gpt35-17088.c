//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "https://download.thinkbroadband.com/10MB.zip"

// Function to measure the internet speed using curl
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    double speed, total_time;
    time_t start, end;

    curl_global_init(CURL_GLOBAL_ALL);

    while(1) {
        printf("Press enter to test the internet speed or type 'quit' to exit: \n");
        char input[10];
        scanf("%s", input);
        if(strcmp(input, "quit") == 0) {
            break;
        }
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, URL);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
            curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
            start = time(NULL);
            res = curl_easy_perform(curl);
            end = time(NULL);
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
            curl_easy_cleanup(curl);
            total_time = difftime(end, start);
            printf("Download speed: %.2f Mbps\n", speed / 1000000);
            printf("Time taken: %.0f seconds\n", total_time);
        }
        else {
            printf("Error: Could not initiate curl.\n");
        }
    }

    curl_global_cleanup();

    return 0;
}