//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "http://speed.hetzner.de/100MB.bin" // A test file for download speed
#define TEST_SIZE 1024 * 1024 // 1 MB for upload speed test
#define UPLOAD_URL "http://httpbin.org/post" // Testing upload speed

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    return realsize; // Ignore the downloaded data
}

double get_download_speed(CURL *curl) {
    struct timeval start, end;
    double elapsed_time;

    gettimeofday(&start, NULL);
    curl_easy_perform(curl);
    gettimeofday(&end, NULL);

    elapsed_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0); // milliseconds

    if (elapsed_time == 0) return 0; // Prevent division by zero
    return (double)(100) / (elapsed_time / 1000.0); // Speed in MB/s
}

double get_upload_speed(CURL *curl) {
    struct timeval start, end;
    double elapsed_time;
    char *data = malloc(TEST_SIZE);
    memset(data, '0', TEST_SIZE); // Fill with dummy data

    gettimeofday(&start, NULL);
    curl_easy_perform(curl);
    gettimeofday(&end, NULL);
    
    free(data); // Clean up dummy data

    elapsed_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0); // milliseconds

    if (elapsed_time == 0) return 0; // Prevent division by zero
    return (double)TEST_SIZE / (elapsed_time / 1000.0) / (1024 * 1024); // Speed in MB/s
}

void test_speed() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Download speed test
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        
        printf("Testing download speed...\n");
        double download_speed = get_download_speed(curl);
        printf("Download speed: %.2f MB/s\n", download_speed);
        
        curl_easy_cleanup(curl);
    }

    // Upload speed test
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        // Specify the POST data
        char *data = malloc(TEST_SIZE);
        memset(data, '0', TEST_SIZE); // Dummy data
        curl_easy_setopt(curl, CURLOPT_READDATA, data);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, TEST_SIZE);

        printf("Testing upload speed...\n");
        double upload_speed = get_upload_speed(curl);
        printf("Upload speed: %.2f MB/s\n", upload_speed);

        free(data);
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
}

int main(void) {
    printf("Internet Speed Test Application\n");
    printf("This will take a moment...\n");

    test_speed();

    return 0;
}