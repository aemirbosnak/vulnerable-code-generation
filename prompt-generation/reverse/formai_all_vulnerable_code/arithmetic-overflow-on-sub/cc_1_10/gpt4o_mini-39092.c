//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

#define FILESIZE 1048576 // 1 MB for testing
#define TEST_URL "http://ipv4.download.thinkbroadband.com/1MB.zip"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

double measure_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    double download_speed;

    char tmp_filename[] = "speed_test_tmp_file";
    fp = fopen(tmp_filename, "wb");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        
        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            fclose(fp);
            return -1;
        }

        fclose(fp);
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &download_speed);

        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time taken to download: %.2f seconds\n", time_taken);
        printf("Download speed: %.2f bytes/sec\n", download_speed);
        
        curl_easy_cleanup(curl);
        remove(tmp_filename); // clean up the temp file
    } else {
        fclose(fp);
        fprintf(stderr, "Curl initialization failed\n");
        return -1;
    }
    return download_speed;
}

void speed_test_recursive(int count) {
    if (count <= 0) {
        printf("Completed speed tests\n");
        return;
    }

    printf("Running speed test %d\n", count);
    measure_speed(TEST_URL);
    
    // Recursive call
    speed_test_recursive(count - 1);
}

int main() {
    int number_of_tests;

    printf("Enter number of speed tests to run: ");
    scanf("%d", &number_of_tests);

    if (number_of_tests <= 0) {
        printf("Please enter a positive integer\n");
        return 1;
    }

    speed_test_recursive(number_of_tests);
    return 0;
}