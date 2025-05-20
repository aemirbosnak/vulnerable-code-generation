//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    char url[1024];
    int is_sanitized;
} UrlInfo;

UrlInfo url_list[] = {
    {"http://www.google.com", 0},
    {"https://www.facebook.com", 0},
    {"ftp://ftp.microsoft.com", 0},
    {"https://www.example.com", 0},
    {"http://www.yahoo.com", 0},
    {"https://www.ibm.com", 0},
    {"ftp://ftp.redhat.com", 0},
    {"https://www.amazon.com", 0},
    {"http://www.wikipedia.org", 0},
    {"https://www.twitter.com", 0}
};

pthread_mutex_t lock;
int num_sanitized = 0;

void *sanitize_urls(void *thread_id)
{
    int tid = *(int*)thread_id;
    int start = tid * (sizeof(url_list) / NUM_THREADS);
    int end = (tid + 1) * (sizeof(url_list) / NUM_THREADS);

    for (int i = start; i < end; i++) {
        // Sanitize the URL
        // ...

        // Update the is_sanitized flag
        pthread_mutex_lock(&lock);
        url_list[i].is_sanitized = 1;
        num_sanitized++;
        pthread_mutex_unlock(&lock);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sanitize_urls, &thread_ids[i]);
    }

    // Wait for the threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check if all the URLs have been sanitized
    while (num_sanitized < sizeof(url_list) / sizeof(url_list[0])) {
        // Wait for some time and check again
        usleep(5000);
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);

    printf("All URLs have been sanitized.\n");

    return 0;
}