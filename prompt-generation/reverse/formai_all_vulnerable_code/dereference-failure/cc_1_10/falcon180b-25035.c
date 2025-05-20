//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    CURL *curl;
    char *url;
} http_client_t;

void *http_client_worker(void *arg) {
    http_client_t *client = (http_client_t *) arg;
    CURLcode res;

    res = curl_easy_setopt(client->curl, CURLOPT_URL, client->url);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_setopt() failed: %s\n", curl_easy_strerror(res));
        exit(EXIT_FAILURE);
    }

    res = curl_easy_perform(client->curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(client->curl);
    free(client->url);
    free(client);

    return NULL;
}

void http_client_async(const char *url, void (*callback)(char *response)) {
    http_client_t *client = (http_client_t *) malloc(sizeof(http_client_t));

    if (client == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    client->curl = curl_easy_init();
    if (client->curl == NULL) {
        fprintf(stderr, "curl_easy_init() failed\n");
        exit(EXIT_FAILURE);
    }

    client->url = strdup(url);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, http_client_worker, client);
}

void http_client_callback(char *response) {
    printf("Response: %s\n", response);
}

int main() {
    http_client_async("https://jsonplaceholder.typicode.com/posts/1", http_client_callback);

    while (1) {
        sleep(1);
    }

    return 0;
}