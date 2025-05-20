//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define MAX_URL_SIZE 2048
#define MAX_DATA_SIZE 1024*1024*10

typedef struct {
    char* url;
    char* data;
    size_t size;
} DownloadData;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    DownloadData* data = (DownloadData*)userp;
    size_t new_size = data->size + size*nmemb;
    if (new_size > MAX_DATA_SIZE) {
        fprintf(stderr, "Error: Maximum data size exceeded.\n");
        exit(1);
    }
    data->data = realloc(data->data, new_size);
    memcpy(data->data + data->size, contents, size*nmemb);
    data->size += size*nmemb;
    return size*nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    char* url;
    long response_code;
    double speed;
    struct timeval start, end;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        printf("Enter URL to test: ");
        scanf("%s", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)malloc(sizeof(DownloadData)));

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            exit(1);
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("Response code: %ld\n", response_code);

        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &speed);
        printf("Download speed: %.2f KB/s\n", speed/1024);

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    } else {
        fprintf(stderr, "Error: Failed to initialize curl.\n");
        exit(1);
    }

    return 0;
}