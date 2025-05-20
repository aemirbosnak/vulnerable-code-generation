//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_THREADS 10

typedef struct {
    char url[MAX_URL_LENGTH];
    int sanitized;
} url_data_t;

void *sanitize_url(void *arg) {
    url_data_t *data = (url_data_t *) arg;
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int i, j;

    for (i = 0, j = 0; i < strlen(data->url); i++) {
        if (isalnum(data->url[i])) {
            sanitized_url[j++] = data->url[i];
        }
    }
    sanitized_url[j] = '\0';

    strcpy(data->url, sanitized_url);
    free(sanitized_url);

    data->sanitized = 1;

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    url_data_t data[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        printf("Enter URL %d: ", i + 1);
        scanf("%s", data[i].url);
        data[i].sanitized = 0;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, sanitize_url, (void *) &data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        printf("Sanitized URL %d: %s\n", i + 1, data[i].url);
    }

    return 0;
}