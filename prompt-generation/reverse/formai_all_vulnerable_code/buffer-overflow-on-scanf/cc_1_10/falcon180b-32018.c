//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <pthread.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *url;
    char *content;
    size_t content_size;
    bool is_finished;
} DownloadThreadData;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    DownloadThreadData *data = (DownloadThreadData *)userp;
    size_t realsize = size * nmemb;
    if (data->content_size + realsize > BUFFER_SIZE) {
        printf("Error: Content size exceeds buffer limit.\n");
        exit(1);
    }
    memcpy(data->content + data->content_size, contents, realsize);
    data->content_size += realsize;
    return realsize;
}

static void *DownloadThread(void *param) {
    DownloadThreadData *data = (DownloadThreadData *)param;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    data->is_finished = true;
    return NULL;
}

int main() {
    pthread_t thread_id;
    DownloadThreadData data;

    printf("Enter the URL to download: ");
    scanf("%s", data.url);

    data.content = (char *)malloc(BUFFER_SIZE);
    data.content_size = 0;
    data.is_finished = false;

    pthread_create(&thread_id, NULL, DownloadThread, &data);

    while (!data.is_finished) {
        printf("Downloading...\n");
        sleep(1);
    }

    printf("Download completed.\n");

    return 0;
}