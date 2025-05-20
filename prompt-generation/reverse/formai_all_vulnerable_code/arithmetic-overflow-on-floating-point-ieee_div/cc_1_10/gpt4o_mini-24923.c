//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define URL "http://www.google.com"
#define BUFFER_SIZE 1024

size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb; // We do nothing with the data
}

double get_download_speed(size_t bytes_received, double time_sec) {
    return (bytes_received * 8) / (time_sec * 1000000); // Convert to Mbps
}

void perform_speed_test() {
    CURL *curl;
    CURLcode res;
    struct timeval start, end;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body

        gettimeofday(&start, NULL);
        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double time_sec = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
            double bytes_received;
            curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &bytes_received);
            double speed_mbps = get_download_speed(bytes_received, time_sec);
            printf("Download Speed: %.2f Mbps\n", speed_mbps);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void display_intro() {
    printf("=== Minimalist Internet Speed Test ===\n");
    printf("Testing download speed using %s\n", URL);
    printf("-------------------------------------\n");
}

int main() {
    display_intro();
    perform_speed_test();
    return 0;
}