//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_URL_LEN 2048
#define MAX_THREADS 10

typedef struct {
    char url[MAX_URL_LEN];
    int url_len;
} url_t;

void *sanitize_url(void *arg) {
    url_t *url_data = (url_t *) arg;
    char *sanitized_url = malloc(MAX_URL_LEN);
    int i = 0, j = 0;

    for (i = 0; i < url_data->url_len; i++) {
        if (isalnum(url_data->url[i]) || url_data->url[i] == '-') {
            sanitized_url[j++] = tolower(url_data->url[i]);
        }
    }
    sanitized_url[j] = '\0';

    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    char input_url[MAX_URL_LEN];

    printf("Enter URLs to sanitize (enter 'done' when finished):\n");

    while (fgets(input_url, MAX_URL_LEN, stdin)!= NULL && strcmp(input_url, "done")) {
        url_t url_data;
        strcpy(url_data.url, input_url);
        url_data.url_len = strlen(url_data.url);

        pthread_create(&threads[thread_count], NULL, sanitize_url, (void *) &url_data);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}