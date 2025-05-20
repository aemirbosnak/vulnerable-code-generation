//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <string.h>

#define TEST_URL "http://speed.hetzner.de/100MB.bin" // URL for testing download speed
#define TEST_UPLOAD_URL "https://httpbin.org/post" // URL for testing upload speed
#define CHUNK_SIZE 1024 * 1024 // 1 MB chunk size for upload

// Function to measure download speed
double measure_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct timeval start, end;

    curl = curl_easy_init();
    if (curl) {
        // Set the URL for the download
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // No need for the body
        gettimeofday(&start, NULL); // Start timing

        res = curl_easy_perform(curl); // Perform the download

        gettimeofday(&end, NULL); // End timing
        curl_easy_cleanup(curl); // Cleanup
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return -1.0; // Return error
        }

        // Calculate the time taken
        double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        return duration; // Return duration in seconds
    }
    return -1.0; // Return error
}

// Function to upload a chunk of data
size_t read_callback(char *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t retcode = fread(ptr, size, nmemb, stream);
    return retcode;
}

// Function to measure upload speed
double measure_upload_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct timeval start, end;
    FILE *hd_src;
    
    hd_src = fopen("/dev/zero", "rb"); // Read from /dev/zero for testing
    if (!hd_src) {
        perror("fopen");
        return -1.0;
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(curl, CURLOPT_READDATA, hd_src);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, CHUNK_SIZE); // Upload 1 MB
        gettimeofday(&start, NULL); // Start timing
        
        res = curl_easy_perform(curl); // Perform the upload

        gettimeofday(&end, NULL); // End timing
        fclose(hd_src); // Close file
        curl_easy_cleanup(curl); // Cleanup
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return -1.0; // Return error
        }

        // Calculate the time taken
        double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        return duration; // Return duration in seconds
    }

    fclose(hd_src); // Close file on failure
    return -1.0; // Return error
}

void print_speed(double duration, const char *action) {
    if (duration <= 0) {
        printf("Speed test for %s failed.\n", action);
    } else {
        double speed = (CHUNK_SIZE / (1024.0 * 1024.0)) / duration; // Speed in MB/s
        printf("Your %s speed: %.2f MB/s\n", action, speed);
    }
}

int main() {
    printf("Welcome to the Lightning Fast Internet Speed Test!\n");
    
    // Measure download speed
    printf("Testing download speed...\n");
    double download_time = measure_download_speed(TEST_URL);
    print_speed(download_time, "download");
    
    // Measure upload speed
    printf("Testing upload speed...\n");
    double upload_time = measure_upload_speed(TEST_UPLOAD_URL);
    print_speed(upload_time, "upload");
    
    printf("Speed test completed, thank you for using our service!\n");
    return 0;
}