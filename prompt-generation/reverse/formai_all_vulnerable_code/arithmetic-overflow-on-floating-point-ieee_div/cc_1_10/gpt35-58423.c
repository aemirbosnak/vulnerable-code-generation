//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <curl/curl.h>

#define DOWNLOAD_URL "http://speedtest.tele2.net/100MB.zip"
#define TEST_DURATION 10 //seconds

static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
    return size * nmemb;
}

double get_speed() {
    CURL *curl = NULL;
    CURLcode res;
    double speed = -1.0;
    time_t start_time, end_time;
    FILE *stream;

    curl = curl_easy_init();
    if(curl) {
        stream = fopen("temp", "w");
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stream);
        start_time = time(NULL);
        res = curl_easy_perform(curl);
        end_time = time(NULL);
        fclose(stream);
        curl_easy_cleanup(curl);
        if(res != CURLE_OK) {
            return speed;
        }
        else {
            speed = (double)104857600 / (double)(end_time - start_time);
            return speed;
        }
    }
    else
        return speed;
}

int main() {
    double speed;
    int i, progress;
    // Initialize the curl library
    curl_global_init(CURL_GLOBAL_ALL);
    // Test the speed for TEST_DURATION seconds
    for(i=0; i<TEST_DURATION; i++) {
        progress = (i*100)/TEST_DURATION;
        printf("Testing: %d%%", progress);
        fflush(stdout);
        speed = get_speed();
        if(speed == -1.0)
            printf("\rFailed to get speed");
        else
            printf("\rAverage speed: %ch%2.2f Kb/s", 37, speed/1024);
        sleep(1);
    }
    // Cleanup the curl library
    curl_global_cleanup();
    return 0;
}