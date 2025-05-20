//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define BUFFER_SIZE 4096
#define TEST_FILE "http://speed.hetzner.de/1MB.bin"
#define UPLOAD_URL "http://example.com/upload" // Replace with actual upload URL

typedef struct {
    double speed; // Speed in Mbps
} SpeedTestResult;

void *download_speed_test(void *arg) {
    CURL *curl;
    CURLcode res;
    double download_time;
    double download_speed;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, TEST_FILE);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);

        // Start timer
        clock_t start_time = clock();
        
        // Perform the download
        res = curl_easy_perform(curl);

        // Finish timer
        download_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
        
        if(res != CURLE_OK) {
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            pthread_exit(NULL);
        }

        // Get the download speed in bytes per second
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &download_speed);
        // Convert speed to Mbps
        download_speed = (download_speed * 8) / (1024 * 1024);

        printf("Download Speed: %.2f Mbps\n", download_speed);
        
        curl_easy_cleanup(curl);
        pthread_exit((void *)&download_speed);
    }
    pthread_exit(NULL);
}

void *upload_speed_test(void *arg) {
    CURL *curl;
    CURLcode res;
    double upload_time;
    double upload_speed;
    FILE *file;
    
    // Create a dummy file to upload
    file = fopen("dummyfile.bin", "wb");
    if (!file) {
        fprintf(stderr, "Could not create dummy file\n");
        pthread_exit(NULL);
    }
    
    char buffer[BUFFER_SIZE];
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 'A';
    }
    fwrite(buffer, 1, BUFFER_SIZE, file);
    fclose(file);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, fopen("dummyfile.bin", "rb"));
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, BUFFER_SIZE);

        // Start timer
        clock_t start_time = clock();
        
        // Perform the upload
        res = curl_easy_perform(curl);

        // Finish timer
        upload_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

        if(res != CURLE_OK) {
            fprintf(stderr, "Upload failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            pthread_exit(NULL);
        }

        // Get the upload speed in bytes per second
        curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &upload_speed);
        // Convert speed to Mbps
        upload_speed = (upload_speed * 8) / (1024 * 1024);

        printf("Upload Speed: %.2f Mbps\n", upload_speed);
        
        curl_easy_cleanup(curl);
    }
    
    // Delete dummy file
    remove("dummyfile.bin");

    pthread_exit(NULL);
}

int main() {
    pthread_t download_thread, upload_thread;
    SpeedTestResult result;

    // Initialize CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create threads to perform download and upload tests
    pthread_create(&download_thread, NULL, download_speed_test, NULL);
    pthread_create(&upload_thread, NULL, upload_speed_test, NULL);
    
    // Wait for both threads to complete
    pthread_join(download_thread, (void **)&result.speed);
    pthread_join(upload_thread, (void **)&result.speed);

    // Cleanup CURL
    curl_global_cleanup();

    return 0;
}