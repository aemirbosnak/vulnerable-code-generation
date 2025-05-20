//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <curl/curl.h>

#define MAX_REQUESTS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *url;
    char *method;
    char *data;
} request_t;

request_t requests[MAX_REQUESTS];
int num_requests = 0;

void *handle_request(void *arg) {
    request_t *req = (request_t *) arg;

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, req->method);
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, req->url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        if(req->data) {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, req->data);
        }

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    free(req->url);
    free(req->method);
    free(req->data);
    free(req);

    return NULL;
}

void add_request(char *url, char *method, char *data) {
    if(num_requests >= MAX_REQUESTS) {
        printf("Maximum number of requests reached\n");
        return;
    }

    request_t *req = &requests[num_requests];
    req->url = strdup(url);
    req->method = strdup(method);
    req->data = strdup(data);

    num_requests++;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, handle_request, (void *) req);
}

int main() {
    add_request("http://localhost:8080/lights/on", "PUT", "{}");
    add_request("http://localhost:8080/lights/off", "PUT", "{}");

    while(num_requests > 0) {
        sleep(1);
    }

    return 0;
}