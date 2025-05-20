//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <sys/time.h>

static size_t write_callback(void *ptr, size_t size, size_t nmemb) {
    return size * nmemb; // Ignore downloaded data
}

double get_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct timeval start, end;

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize CURL\n");
        return 0.0;
    }

    gettimeofday(&start, NULL);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);  // We don't need the response body
    res = curl_easy_perform(curl);
    
    gettimeofday(&end, NULL);
    
    long response_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 0.0;
    }

    // Estimate download speed in Mbps
    double speed = (8.0 / (response_time / 1000000.0)); // bits per second
    return speed / 1e6; // Converted to Mbps
}

double get_upload_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct timeval start, end;
    const char *data = "Test data for upload speed"; // Dummy data
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize CURL\n");
        return 0.0;
    }

    gettimeofday(&start, NULL);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_READDATA, data);
    curl_easy_setopt(curl, CURLOPT_INFILESIZE, (long)strlen(data));
    
    res = curl_easy_perform(curl);
    
    gettimeofday(&end, NULL);
    
    long response_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 0.0;
    }

    // Estimate upload speed in Mbps
    double speed = (8.0 * strlen(data) / (response_time / 1000000.0)); // bits per second
    return speed / 1e6; // Converted to Mbps
}

int main(void) {
    const char *download_url = "http://ipv4.download.thinkbroadband.com/5MB.zip"; // Example URL for download test
    const char *upload_url = "http://httpbin.org/post"; // Example URL for upload test
    
    printf("Starting Internet Speed Test...\n");

    double download_speed = get_download_speed(download_url);
    double upload_speed = get_upload_speed(upload_url);

    if (download_speed > 0) {
        printf("Download Speed: %.2f Mbps\n", download_speed);
    } else {
        printf("Could not measure download speed.\n");
    }

    if (upload_speed > 0) {
        printf("Upload Speed: %.2f Mbps\n", upload_speed);
    } else {
        printf("Could not measure upload speed.\n");
    }
    
    return 0;
}