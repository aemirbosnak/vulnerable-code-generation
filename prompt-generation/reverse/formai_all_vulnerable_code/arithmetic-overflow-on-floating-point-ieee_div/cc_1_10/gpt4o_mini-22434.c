//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define URL "http://test-server/upload" // Replace with an actual speed test server URL

typedef struct {
    char *url;
    double speed;
} SpeedTestData;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb; // Ignore data
}

void *download_speed_test(void *data) {
    SpeedTestData *test_data = (SpeedTestData *)data;
    CURL *curl;
    CURLcode res;
    long download_time;
    double speed;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, test_data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body for speed testing

        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        if(CURLE_OK == res) {
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &download_time);
            speed = 1.0 / ((double)download_time / CLOCKS_PER_SEC); // Calculate speed
            test_data->speed = speed;
            printf("Download Speed: %.2f MB/s\n", speed);
        } else {
            fprintf(stderr, "Download error: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return NULL;
}

void *upload_speed_test(void *data) {
    SpeedTestData *test_data = (SpeedTestData *)data;
    CURL *curl;
    CURLcode res;
    long upload_time = 0;
    double speed;

    curl = curl_easy_init();
    if(curl) {
        char payload[1024] = "Test data for upload speed test."; // Sample data for upload
        curl_easy_setopt(curl, CURLOPT_URL, test_data->url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);

        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        if(CURLE_OK == res) {
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &upload_time);
            speed = 1.0 / ((double)upload_time / CLOCKS_PER_SEC);
            test_data->speed = speed;
            printf("Upload Speed: %.2f MB/s\n", speed);
        } else {
            fprintf(stderr, "Upload error: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return NULL;
}

int main(void) {
    pthread_t download_thread, upload_thread;
    SpeedTestData download_data = {URL, 0.0};
    SpeedTestData upload_data = {URL, 0.0};

    printf("Starting Speed Test...\n");

    pthread_create(&download_thread, NULL, download_speed_test, &download_data);
    pthread_create(&upload_thread, NULL, upload_speed_test, &upload_data);

    pthread_join(download_thread, NULL);
    pthread_join(upload_thread, NULL);

    printf("Speed Test Completed.\n");
    return 0;
}