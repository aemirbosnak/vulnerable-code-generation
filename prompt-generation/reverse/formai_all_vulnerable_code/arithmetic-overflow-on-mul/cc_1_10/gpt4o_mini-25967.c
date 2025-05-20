//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <sys/time.h>

#define DOWNLOAD_URL "http://ipv4.download.thinkbroadband.com/10MB.zip" // Example download file
#define UPLOAD_URL "http://httpbin.org/post" // Example upload endpoint

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb; // We don't use the data, just discard it
}

double get_download_speed() {
    CURL *curl;
    CURLcode res;
    struct timeval start, end;
    double elapsed_time, download_speed;

    curl = curl_easy_init();
    if (curl) {
        gettimeofday(&start, NULL); // Record start time

        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only need the headers and connection speed

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error in download: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1;
        }

        gettimeofday(&end, NULL); // Record end time
        elapsed_time = ((end.tv_sec - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6; // Calculate elapsed time in seconds
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &download_speed);

        curl_easy_cleanup(curl);
    }

    return download_speed;
}

double get_upload_speed() {
    CURL *curl;
    CURLcode res;
    struct timeval start, end;
    double elapsed_time, upload_speed;
    const char *data = "test data";
    struct curl_slist *headers = NULL;

    curl = curl_easy_init();
    if (curl) {
        gettimeofday(&start, NULL); // Record start time

        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error in upload: %s\n", curl_easy_strerror(res));
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
            return -1;
        }

        gettimeofday(&end, NULL); // Record end time
        elapsed_time = ((end.tv_sec - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6; // Calculate elapsed time in seconds
        curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &upload_speed);

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return upload_speed;
}

int main() {
    double download_speed = get_download_speed();
    double upload_speed = get_upload_speed();

    if (download_speed < 0 || upload_speed < 0) {
        fprintf(stderr, "Speed test failed!\n");
        return EXIT_FAILURE;
    }

    printf("Download Speed: %.2f bytes/sec\n", download_speed);
    printf("Upload Speed: %.2f bytes/sec\n", upload_speed);

    return EXIT_SUCCESS;
}