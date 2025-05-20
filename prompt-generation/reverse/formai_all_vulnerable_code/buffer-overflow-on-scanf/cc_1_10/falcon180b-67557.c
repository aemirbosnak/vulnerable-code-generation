//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_REQUESTS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *url;
    char *response;
    int response_len;
} Request;

void *handle_request(void *arg) {
    Request *request = (Request *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    FILE *fp = fopen(request->url, "r");
    if (fp == NULL) {
        strcpy(request->response, "File not found");
        request->response_len = strlen(request->response);
        return NULL;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        request->response = realloc(request->response, request->response_len + bytes_read);
        strncat(request->response, buffer, bytes_read);
        request->response_len += bytes_read;
    }

    fclose(fp);
    return NULL;
}

int main() {
    pthread_t threads[MAX_REQUESTS];
    Request requests[MAX_REQUESTS];
    int i, num_requests;

    printf("Enter number of requests: ");
    scanf("%d", &num_requests);

    for (i = 0; i < num_requests; i++) {
        printf("Enter URL for request %d: ", i + 1);
        scanf("%s", requests[i].url);
        requests[i].response = malloc(1);
        requests[i].response_len = 0;
    }

    for (i = 0; i < num_requests; i++) {
        pthread_create(&threads[i], NULL, handle_request, &requests[i]);
    }

    for (i = 0; i < num_requests; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_requests; i++) {
        printf("Request %d: %s\n", i + 1, requests[i].response);
        free(requests[i].response);
    }

    return 0;
}