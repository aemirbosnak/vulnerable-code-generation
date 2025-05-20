//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <curl/curl.h>

#define BUFFER_SIZE 1024

// Function to write data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

// Function to display progress
int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    double progress = (double)dlnow / dltotal * 100.0;
    printf("%.2f%%\r", progress);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <URL> <output file>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char url[1024];
        strcpy(url, argv[1]);

        fp = fopen(argv[2], "wb");
        if (!fp) {
            printf("Failed to open output file.\n");
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Failed to download URL: %s\n", curl_easy_strerror(res));
            fclose(fp);
            remove(argv[2]);
            return 1;
        }

        fclose(fp);
        printf("\nDownload complete.\n");
    }

    curl_global_cleanup();
    return 0;
}