//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define RESPONSE_SIZE 100000

// A structure to hold the response from the speed test
struct response_data {
    char data[RESPONSE_SIZE];
    size_t size;
};

// Callback function to write data received from the server
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct response_data *data) {
    size_t total_size = size * nmemb;

    if (data->size + total_size >= RESPONSE_SIZE - 1) {
        fprintf(stderr, "Response too large for buffer\n");
        return 0; // To indicate an error in writing
    }

    memcpy(&(data->data[data->size]), ptr, total_size);
    data->size += total_size;
    data->data[data->size] = '\0'; // Null-terminate the string
    return total_size;
}

// Function to perform a speed test by downloading a file
void download_speed_test() {
    CURL *curl;
    CURLcode res;
    struct response_data data;
    data.size = 0;

    printf("\n=== Starting Download Speed Test ===\n");

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://ipv4.download.thinkbroadband.com/10MB.zip"); // A 10 MB test file
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); // Disable progress meter
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L); // Timeout after 30 seconds

        time_t start = time(NULL);
        res = curl_easy_perform(curl);
        time_t end = time(NULL);
        
        if (res == CURLE_OK) {
            double download_time = difftime(end, start);
            double speed_mbps = (10000.0 / download_time) * 0.000008; // Convert to Megabits per second
            printf("Download completed successfully!\n");
            printf("Time taken: %.2f seconds\n", download_time);
            printf("Speed: %.2f Mbps\n", speed_mbps);
        } else {
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }

    curl_global_cleanup();
}

// Function to simulate an upload speed test
void upload_speed_test() {
    CURL *curl;
    CURLcode res;

    printf("\n=== Starting Upload Speed Test ===\n");

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post"); // Example URL for a POST
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        // This data will be uploaded during the test
        const char *data = "Testing upload speed...";
        curl_easy_setopt(curl, CURLOPT_READDATA, data);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, strlen(data));
        
        time_t start = time(NULL);
        res = curl_easy_perform(curl);
        time_t end = time(NULL);

        if (res == CURLE_OK) {
            double upload_time = difftime(end, start);
            double speed_mbps = (strlen(data) / upload_time) * 0.000008; // Convert to Megabits per second
            printf("Upload completed successfully!\n");
            printf("Time taken: %.2f seconds\n", upload_time);
            printf("Speed: %.2f Mbps\n", speed_mbps);
        } else {
            fprintf(stderr, "Upload failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }

    curl_global_cleanup();
}

int main() {
    printf("Welcome to the C Internet Speed Test!\n\n");
    
    download_speed_test();
    upload_speed_test();
    
    printf("\n=== Test completed! Thank you for using the speed test ===\n");
    
    return 0;
}