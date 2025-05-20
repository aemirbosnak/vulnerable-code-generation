//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URL_SIZE 2048

struct url_data {
    char *url;
    void *user_data;
};

size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
    char *response = (char *)malloc(size * nmemb);
    memcpy(response, buffer, size * nmemb);
    printf("%s\n", response);
    free(response);
    return size * nmemb;
}

void *fetch_url(void *arg) {
    struct url_data *data = (struct url_data *)arg;
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    free(data->url);
    free(data);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t thread_id;
    int i;
    struct url_data *data;

    if (argc < 2) {
        printf("Usage: %s URL\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        data = (struct url_data *)malloc(sizeof(struct url_data));
        data->url = strdup(argv[i]);
        pthread_create(&thread_id, NULL, fetch_url, data);
        pthread_detach(thread_id);
    }

    return 0;
}