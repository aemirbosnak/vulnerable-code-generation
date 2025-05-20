//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "http://ipv4.download.thinkbroadband.com/1MB.zip" // Sample file URL for download
#define BUFFER_SIZE 1024 // Size of buffer for data download

// Function to write data to buffer
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

// Function to measure download speed
void test_internet_speed() {
    CURL *curl;
    CURLcode res;
    
    FILE *file;
    double total_time;

    // Start measuring time
    struct timeval start, end;
    gettimeofday(&start, NULL);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        // Open file to write downloaded data
        file = fopen("test_file.zip", "wb");
        if (!file) {
            fprintf(stderr, "Error: Couldn't open file for writing.\n");
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 5L);

        // Perform the download
        res = curl_easy_perform(curl);
        
        // Close the file
        fclose(file);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        } else {
            // Measure end time
            gettimeofday(&end, NULL);
            total_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
            printf("Download completed successfully.\n");

            // Get the file size
            long file_size;
            curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &file_size);

            // Calculate speed in KB/s
            double speed = (file_size / 1024.0) / (total_time / 1000.0);
            printf("Downloaded: %.2lf KB in %.2lf seconds.\n", file_size / 1024.0, total_time / 1000.0);
            printf("Speed: %.2lf KB/s\n", speed);
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Initiating speed test...\n");

    test_internet_speed();

    printf("Cleaning up...\n");
    remove("test_file.zip"); // Clean up the downloaded file
    printf("Test completed. Have a great day!\n");

    return 0;
}