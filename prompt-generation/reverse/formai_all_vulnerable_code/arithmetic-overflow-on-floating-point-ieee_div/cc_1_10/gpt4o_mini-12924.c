//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <sys/time.h>

double get_download_speed(const char* url);
double get_upload_speed(const char* url, const char* data, size_t data_len);

int main() {
    const char* download_url = "http://speed.hetzner.de/100MB.bin";
    const char* upload_url = "http://httpbin.org/post";
    const char* upload_data = "This is a test data for upload speed.";
    size_t upload_data_len = strlen(upload_data);

    // Get and print download speed
    printf("Testing download speed...\n");
    double download_speed = get_download_speed(download_url);
    printf("Download Speed: %.2f MB/s\n", download_speed);

    // Get and print upload speed
    printf("Testing upload speed...\n");
    double upload_speed = get_upload_speed(upload_url, upload_data, upload_data_len);
    printf("Upload Speed: %.2f MB/s\n", upload_speed);

    return 0;
}

size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb; // Not storing the data, just to satisfy curl
}

double get_download_speed(const char* url) {
    CURL* curl;
    CURLcode res;
    struct timeval start, end;

    curl = curl_easy_init();
    if(curl) {
        gettimeofday(&start, NULL);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // seconds
        double download_speed = (100.0 / elapsed_time) / (1024 * 1024); // MB/s

        curl_easy_cleanup(curl);
        return download_speed;
    }
    return 0.0;
}

double get_upload_speed(const char* url, const char* data, size_t data_len) {
    CURL* curl;
    CURLcode res;
    struct timeval start, end;

    curl = curl_easy_init();
    if(curl) {
        gettimeofday(&start, NULL);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data_len);
        
        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // seconds
        double upload_speed = (data_len / 1024.0 / 1024.0) / elapsed_time; // MB/s

        curl_easy_cleanup(curl);
        return upload_speed;
    }
    return 0.0;
}