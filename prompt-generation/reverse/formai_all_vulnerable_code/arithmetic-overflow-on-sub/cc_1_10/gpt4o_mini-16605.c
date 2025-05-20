//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URLS 5
#define BUFFER_SIZE 1024
#define TIMEOUT 10

typedef struct {
    char *url;
    double download_speed;
} SpeedTestResult;

void *test_speed(void *arg) {
    SpeedTestResult *result = (SpeedTestResult *)arg;
    CURL *curl;
    CURLcode res;
    double download_time;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, result->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Only fetch headers for speed

        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        if (res == CURLE_OK) {
            download_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            result->download_speed = (BUFFER_SIZE / download_time) / 1024; // speed in KB/s
        } else {
            result->download_speed = -1; // Error
        }

        curl_easy_cleanup(curl);
    }
    return NULL;
}

void print_speed_results(SpeedTestResult results[], int count) {
    printf("\nDownload Speed Test Results:\n");
    printf("====================================\n");
    for (int i = 0; i < count; i++) {
        if (results[i].download_speed >= 0) {
            printf("URL: %s - Speed: %.2f KB/s\n", results[i].url, results[i].download_speed);
        } else {
            printf("URL: %s - Speed test failed.\n", results[i].url);
        }
    }
    printf("====================================\n");
}

int main() {
    pthread_t threads[MAX_URLS];
    SpeedTestResult results[MAX_URLS];
    
    char *urls[MAX_URLS] = {
        "http://speed.hetzner.de/100MB.bin",
        "https://ipv4.download.thinkbroadband.com/100MB.zip",
        "http://speedtest.ftp.otenet.gr/files/test1Mb.db",
        "http://ipv4.download.speedtest.com/1MB.zip",
        "http://www.iana.org/_img/2018/iana-logo-header.png"
    };

    for (int i = 0; i < MAX_URLS; i++) {
        results[i].url = urls[i];
        results[i].download_speed = 0.0;
        pthread_create(&threads[i], NULL, test_speed, (void *)&results[i]);
    }

    for (int i = 0; i < MAX_URLS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_speed_results(results, MAX_URLS);
    
    return EXIT_SUCCESS;
}