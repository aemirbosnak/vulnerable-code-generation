//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <curl/curl.h>

double calculate_time_diff(struct timeval start, struct timeval end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
}

void print_speed_result(double time_elapsed, long size) {
    double speed = (double)size / time_elapsed;
    printf("\nDownload Speed: %.2f Mbps\n", speed / 1000000.0);
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main() {
    CURL *curl_handle;
    CURLcode res;
    char *url = "http://ipv4.download.thinkbroadband.com/1GB.zip";
    long size = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);

    struct timeval start, end;

    gettimeofday(&start, NULL);

    res = curl_easy_perform(curl_handle);

    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    else {
        curl_easy_getinfo(curl_handle, CURLINFO_SIZE_DOWNLOAD, &size);
        gettimeofday(&end, NULL);
        double time_elapsed = calculate_time_diff(start, end);
        print_speed_result(time_elapsed, size);
    }

    curl_easy_cleanup(curl_handle);

    curl_global_cleanup();

    return 0;
}