//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_SIZE 2048

// Function to get current time in milliseconds
long get_current_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

// Function to perform speed test
size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    FILE *file = (FILE *)userp;
    return fwrite(ptr, size, nmemb, file);
}

// Function to display speed test results
void display_results(double speed) {
    printf("Your internet speed is: %.2f Mbps\n", speed);
}

int main(int argc, char *argv[]) {
    if(argc!= 2) {
        printf("Usage: %s <server_url>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[MAX_URL_SIZE];
        strcpy(url, argv[1]);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            printf("Speed test failed: %s\n", curl_easy_strerror(res));
        } else {
            long start_time = get_current_time_ms();
            long end_time;

            while(curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &end_time)!= CURLE_OK) {
                usleep(100000);
            }

            double speed = (double)(end_time - start_time) / ((double)curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, NULL) / 1024.0 / 1024.0);

            display_results(speed);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}