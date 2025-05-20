//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://speed.hetzner.de/100MB.bin" // A sample test file

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb; // We don't need to actually store the downloaded file
}

void display_results(double download_time, double speed) {
    printf("\x1b[32m"); // Green text
    printf("🎉 🎊 Hooray! 🎊 🎉\n");
    printf("Your internet speed test is complete! 🌍\n");
    printf("-----------------------------------------\n");
    printf("Download time: %.2f seconds\n", download_time);
    printf("Download speed: %.2f MB/s\n", speed);
    printf("-----------------------------------------\n");
    printf("Keep surfing happily! 🌊\n");
    printf("\x1b[0m"); // Reset text color
}

double test_speed() {
    CURL *curl;
    CURLcode res;
    double download_time;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        
        // Measure download time
        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1;
        }

        // Calculate time taken
        download_time = (double)(end - start) / CLOCKS_PER_SEC;
        curl_easy_cleanup(curl);
    }
    return download_time;
}

double calculate_speed(double download_time) {
    if (download_time <= 0) return 0;
    double file_size = 100.0; // Size of the test file in MB
    return file_size / download_time; // Speed in MB/s
}

int main(void) {
    printf("\x1b[34m"); // Blue text
    printf("Welcome to the Happy Internet Speed Test! 🚀\n");
    printf("Let's find out how fast your connection is...\n");
    printf("Please wait while we conduct the test...\n");
    printf("\x1b[0m"); // Reset text color

    // Start the speed test
    double download_time = test_speed();
    
    if (download_time >= 0) {
        double speed = calculate_speed(download_time);
        display_results(download_time, speed);
    } else {
        printf("🚨 Oops! Something went wrong during the test. Please try again later.\n");
    }

    // Ending message
    printf("\nThank you for using the Happy Internet Speed Test! 😊\n");
    printf("Have a fantastic day! 🌈\n");
    return 0;
}