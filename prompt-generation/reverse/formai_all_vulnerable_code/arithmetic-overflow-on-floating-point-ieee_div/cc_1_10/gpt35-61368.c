//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

// define constants for download and upload size
#define DOWNLOAD_SIZE 104857600 // 100 MB
#define UPLOAD_SIZE 5242880 // 5 MB

// function to perform file download
size_t downloadData(void* buffer, size_t itemSize, size_t numItems, void* userData) {
    // do nothing, just discard downloaded data
    return itemSize * numItems;
}

// function to perform file upload
size_t uploadData(void* buffer, size_t itemSize, size_t numItems, void* userData) {
    // simulate uploaded data
    return itemSize * numItems;
}

int main() {
    // setup CURL library
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();

    // perform download speed test
    printf("Testing download speed...\n");
    clock_t downloadStart = clock();

    // set download options
    curl_easy_setopt(curl, CURLOPT_URL, "http://ipv4.download.thinkbroadband.com/100MB.zip");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, downloadData);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, 1000L);

    // perform download test
    CURLcode downloadCode = curl_easy_perform(curl);
    if(downloadCode == CURLE_OK) {
        clock_t downloadEnd = clock();
        double downloadTime = (double)(downloadEnd - downloadStart) / CLOCKS_PER_SEC;
        double downloadSpeed = (double)DOWNLOAD_SIZE / downloadTime / 1000000;
        printf("Download speed: %.2f Mbps\n", downloadSpeed);
    } else {
        printf("Download test failed: %s\n", curl_easy_strerror(downloadCode));
    }

    // perform upload speed test
    printf("Testing upload speed...\n");
    clock_t uploadStart = clock();

    // generate random data for upload test
    char* uploadData = malloc(UPLOAD_SIZE);
    if(uploadData == NULL) {
        printf("Upload test failed: Failed to allocate memory.\n");
        return 1; // exit program
    }

    for(int i=0; i<UPLOAD_SIZE; i++) {
        uploadData[i] = rand() % 256; // random data
    }

    // set upload options
    curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, uploadData);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "Content-Type: application/octet-stream");
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, UPLOAD_SIZE);
    curl_easy_setopt(curl, CURLOPT_MAX_SEND_SPEED_LARGE, 1000L);

    // perform upload test
    CURLcode uploadCode = curl_easy_perform(curl);
    if(uploadCode == CURLE_OK) {
        clock_t uploadEnd = clock();
        double uploadTime = (double)(uploadEnd - uploadStart) / CLOCKS_PER_SEC;
        double uploadSpeed = (double)UPLOAD_SIZE / uploadTime / 1000000;
        printf("Upload speed: %.2f Mbps\n", uploadSpeed);
    } else {
        printf("Upload test failed: %s\n", curl_easy_strerror(uploadCode));
    }

    // cleanup CURL library
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0; // exit program
}