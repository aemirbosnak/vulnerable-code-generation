//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_URL_LENGTH 2048

typedef struct {
    char url[MAX_URL_LENGTH];
    int sanitized;
} url_data;

void *sanitize_url(void *arg) {
    url_data *data = (url_data *) arg;

    if (data->sanitized) {
        return NULL;
    }

    char *ptr = data->url;
    while (*ptr) {
        if (!isalnum(*ptr) && *ptr!= '.' && *ptr!= '-') {
            *ptr = '_';
        }
        ptr++;
    }

    data->sanitized = 1;

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    url_data data[MAX_THREADS];

    int num_threads = 0;

    while (num_threads < MAX_THREADS && scanf("%s", data[num_threads].url)!= EOF) {
        pthread_create(&threads[num_threads], NULL, sanitize_url, &data[num_threads]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        printf("%s\n", data[i].url);
    }

    return 0;
}