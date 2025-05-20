//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define URL "http://ipv4.download.thinkbroadband.com/5MB.zip"
#define NUM_TESTS 5

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return size * nmemb;
}

void perform_speed_test(int test_number, double *average_speed) {
    if (test_number > NUM_TESTS) {
        return;
    }

    CURL *curl;
    CURLcode res;
    FILE *temp_file;
    double speed = 0.0;

    temp_file = fopen("temp_download_file", "wb");
    if (!temp_file) {
        fprintf(stderr, "Could not open temporary file.\n");
        return;
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, temp_file);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);

        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double download_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            double file_size = 5.0 * 1024 * 1024; // 5MB in bytes
            speed = file_size / download_time; // bytes per second
            *average_speed += speed;
            printf("Test %d: Download speed: %.2f bytes/sec\n", test_number, speed);
        }

        curl_easy_cleanup(curl);
    }

    fclose(temp_file);
    remove("temp_download_file");

    // Recursive call
    perform_speed_test(test_number + 1, average_speed);
}

int main() {
    double average_speed = 0.0;

    printf("Starting the Internet Speed Test...\n");
    perform_speed_test(1, &average_speed);

    average_speed /= NUM_TESTS; // Calculate average speed over tests
    printf("Average Speed over %d tests: %.2f bytes/sec\n", NUM_TESTS, average_speed);

    return 0;
}