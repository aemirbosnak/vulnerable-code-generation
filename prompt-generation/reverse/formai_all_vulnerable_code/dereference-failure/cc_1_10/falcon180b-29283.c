//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <curl/curl.h>

struct url_data {
    char *url;
    char *response;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void *fetch_url(void *param) {
    struct url_data *data = (struct url_data *) param;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            strcpy(data->response, "Request completed successfully");
        }
        curl_easy_cleanup(curl);
    }
    return NULL;
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    struct url_data data[num_threads];

    for(int i = 0; i < num_threads; i++) {
        sprintf(data[i].url, "http://example.com/thread_%d", i+1);
        data[i].response[0] = '\0';
        pthread_create(&threads[i], NULL, fetch_url, (void *) &data[i]);
    }

    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}