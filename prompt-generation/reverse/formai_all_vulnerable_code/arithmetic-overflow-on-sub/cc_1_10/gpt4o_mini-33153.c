//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <curl/curl.h>

#define BUFSIZE 1024

// Struct for testing data reception
struct download_data {
    char buffer[BUFSIZE];
    size_t total_size;
};

// Callback function to write data into our buffer
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct download_data *data) {
    size_t total_size = size * nmemb;

    // Check and store received data 
    if (data->total_size + total_size < BUFSIZE) {
        memcpy(data->buffer + data->total_size, ptr, total_size);
        data->total_size += total_size;
        data->buffer[data->total_size] = '\0'; // Null-terminate the string
    }
    return total_size;
}

// Function to test download speed
void test_download_speed(const char *url) {
    struct download_data data;
    data.total_size = 0;

    CURL *curl;
    CURLcode res;
    struct timeval start_time, end_time;

    // Initialize CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // Set the URL for the request
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        // Start timing
        gettimeofday(&start_time, NULL);

        // Perform the request
        res = curl_easy_perform(curl);

        // End timing
        gettimeofday(&end_time, NULL);

        // Calculate elapsed time
        long seconds = end_time.tv_sec - start_time.tv_sec;
        long microseconds = end_time.tv_usec - start_time.tv_usec;
        double elapsed = seconds + microseconds * 1e-6; // seconds as double

        // Cleanup
        curl_easy_cleanup(curl);
        curl_global_cleanup();

        // Check for any errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return;
        }

        // Calculate download speed (bytes/sec)
        double speed = data.total_size / elapsed;

        // Display results
        printf("\n--- Internet Speed Test ---\n");
        printf("URL Used: %s\n", url);
        printf("Data Downloaded: %zu bytes\n", data.total_size);
        printf("Time Taken: %.2f seconds\n", elapsed);
        printf("Download Speed: %.2f bytes/sec (%.2f KB/sec)\n", speed, speed / 1024);
    } else {
        fprintf(stderr, "Failed to initialize CURL.\n");
    }
}

int main() {
    char *url = "http://ipv4.download.thinkbroadband.com/5MB.zip"; // URL for download
    char user_input[10];

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This tool will measure your download speed.\n");

    while(1) {
        printf("Press 'R' to start the speed test or 'Q' to quit: ");
        fgets(user_input, sizeof(user_input), stdin);
        
        // Check if the user wants to quit
        if (strcasecmp(user_input, "Q\n") == 0) {
            printf("Goodbye! Thanks for using the Internet Speed Test.\n");
            exit(0);
        }

        // Only start the test if the user pressed 'R'
        if (strcasecmp(user_input, "R\n") == 0) {
            printf("Starting speed test...\n");
            test_download_speed(url);
        } else {
            printf("Invalid input! Please try again.\n");
        }
    }

    return 0;
}