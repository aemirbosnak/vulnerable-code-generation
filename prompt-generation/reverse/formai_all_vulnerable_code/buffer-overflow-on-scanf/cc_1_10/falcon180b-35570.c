//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 10

struct thread_data {
    char *url;
    int id;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void *download_file(void *arg) {
    struct thread_data *data = arg;
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen(data->url, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "Thread %d: Download failed: %s\n", data->id,
                    curl_easy_strerror(res));

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return NULL;
}

int main() {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    int num_threads;
    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the URLs to download (one per line):\n");
    for(int i=0; i<num_threads; i++) {
        fgets(data[i].url, sizeof(data[i].url), stdin);
        data[i].id = i+1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen("results.txt", "w");
        for(int i=0; i<num_threads; i++) {
            pthread_create(&threads[i], NULL, download_file, &data[i]);
        }

        for(int i=0; i<num_threads; i++) {
            pthread_join(threads[i], NULL);
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}