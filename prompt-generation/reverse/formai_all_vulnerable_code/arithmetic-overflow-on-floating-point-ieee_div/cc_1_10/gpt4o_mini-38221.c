//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://speed.hetzner.de/100MB.bin" // Sample test URL
#define BUFFER_SIZE 32768 // Size of buffer for downloading

// Function to write data to a buffer
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

// Function to perform speed test
void speed_test() {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    time_t start_time, end_time;
    double elapsed_time;

    // Initialize CURL
    curl = curl_easy_init();
    if (curl) {
        fp = fopen("testfile.bin", "wb"); // Open file to write
        if (!fp) {
            fprintf(stderr, "Failed to create file.\n");
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Get the starting time
        start_time = time(NULL);

        // Perform the file download
        res = curl_easy_perform(curl);

        // Get the ending time
        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Calculate speed in MB/s
            fseek(fp, 0, SEEK_END);
            long file_size = ftell(fp);
            rewind(fp);
            if (elapsed_time > 0) {
                double speed_mbps = (file_size / (1024.0 * 1024.0)) / elapsed_time;
                printf("Download Speed: %.2f MB/s\n", speed_mbps);
            } else {
                printf("Elapsed time is zero, cannot calculate speed.\n");
            }
        }
        fclose(fp);
        curl_easy_cleanup(curl); // Clean up CURL
        remove("testfile.bin"); // Optional: delete test file
    } else {
        fprintf(stderr, "Curl initialization failed!\n");
    }
}

// Animation function to show progress
void display_progress() {
    const char *spinner = "|/-\\";
    for (int i = 0; i < 20; i++) {
        printf("\rTesting speed... %c  ", spinner[i % 4]);
        fflush(stdout);
        usleep(100000); // Sleep for 100ms
    }
    printf("\rDone!                \n");
}

int main() {
    printf("Welcome to the Internet Speed Test Application\n");
    printf("This will measure your current download speed.\n\n");
    
    display_progress(); // Show spinner while testing speed
    speed_test(); // Execute speed test
    
    printf("\nThank you for using the Speed Test Application!\n");

    return 0;
}