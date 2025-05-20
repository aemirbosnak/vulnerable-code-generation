//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 1000

typedef struct {
    char url[1024];
    char method[10];
    char data[1024];
} Request;

typedef struct {
    CURL *curl;
    Request request;
} ThreadData;

void *threadFunction(void *arg) {
    ThreadData *threadData = (ThreadData *) arg;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_easy_setopt(threadData->curl, CURLOPT_URL, threadData->request.url);
    curl_easy_setopt(threadData->curl, CURLOPT_CUSTOMREQUEST, threadData->request.method);
    curl_easy_setopt(threadData->curl, CURLOPT_POSTFIELDS, threadData->request.data);
    curl_easy_perform(threadData->curl);
    curl_easy_cleanup(threadData->curl);
    curl_global_cleanup();

    return NULL;
}

int main() {
    FILE *file;
    char line[1024];
    int numRequests = 0;

    file = fopen("requests.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (numRequests >= MAX_REQUESTS) {
            printf("Maximum number of requests reached.\n");
            break;
        }

        Request request;
        sscanf(line, "%s %s %s", request.url, request.method, request.data);

        pthread_t threadId;
        pthread_create(&threadId, NULL, threadFunction, (void *) &request);
        numRequests++;
    }

    fclose(file);

    return 0;
}