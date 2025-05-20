//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_URLS 1000
#define MAX_THREADS 10

typedef struct {
    char url[1024];
    int is_valid;
} url_t;

void *sanitize_url(void *arg) {
    url_t *url = (url_t *) arg;
    char *ptr = url->url;
    int len = strlen(ptr);
    int i = 0;

    while (i < len) {
        if (!isalnum(ptr[i]) && ptr[i]!= '.' && ptr[i]!= '-' && ptr[i]!= '_') {
            ptr[i] = '_';
        }
        i++;
    }

    url->is_valid = 1;
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    url_t urls[MAX_URLS];
    int num_urls = 0;
    int max_threads = MAX_THREADS;

    printf("Enter URLs (Press Enter after each URL):\n");
    while (num_urls < MAX_URLS && scanf("%s", urls[num_urls].url)!= EOF) {
        num_urls++;
    }

    printf("Sanitizing %d URLs using %d threads...\n", num_urls, max_threads);

    for (int i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, sanitize_url, &urls[i]);
    }

    for (int i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("URL Sanitization complete!\n");

    return 0;
}