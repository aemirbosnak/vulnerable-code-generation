//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define BUFFER_SIZE 2048
#define MAX_URLS 100
#define THREAD_COUNT 4

char *urls[MAX_URLS];
char *sanitized_urls[MAX_URLS];
int url_count = 0;

pthread_mutex_t lock;

void *sanitize_url(void *arg) {
    int index = *(int *)arg;
    char *url = urls[index];
    char *sanitized_url = malloc(BUFFER_SIZE);
    int j = 0;
    
    for (int i = 0; url[i] != '\0'; i++) {
        // Only allow alphanumeric characters, some special characters, and avoid spaces
        if (isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '~' || 
            url[i] == ':' || url[i] == '/' || url[i] == '?' || url[i] == '&' || url[i] == '=' || url[i] == '%') {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    
    pthread_mutex_lock(&lock);
    sanitized_urls[index] = sanitized_url;
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

void print_sanitized_urls() {
    printf("Sanitized URLs:\n");
    for (int i = 0; i < url_count; i++) {
        printf("%s\n", sanitized_urls[i]);
        free(sanitized_urls[i]); // Free each sanitized URL after printing
    }
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_indices[THREAD_COUNT];
    
    printf("Enter the number of URLs (max %d): ", MAX_URLS);
    scanf("%d", &url_count);
    
    if(url_count > MAX_URLS) {
        printf("URL count exceeds maximum limit. Setting to %d.\n", MAX_URLS);
        url_count = MAX_URLS;
    }
    
    for (int i = 0; i < url_count; i++) {
        urls[i] = malloc(BUFFER_SIZE);
        printf("Enter URL %d: ", i + 1);
        scanf("%s", urls[i]);
    }

    pthread_mutex_init(&lock, NULL);
    
    // Create threads to sanitize URLs
    for (int i = 0; i < url_count; i++) {
        thread_indices[i % THREAD_COUNT] = i; // Assign the index to the thread
        if (i >= THREAD_COUNT) {
            pthread_join(threads[i % THREAD_COUNT], NULL); // Wait for the current threads to finish
        }
        pthread_create(&threads[i % THREAD_COUNT], NULL, sanitize_url, &thread_indices[i % THREAD_COUNT]);
    }
    
    // Wait for remaining threads to finish
    for (int i = 0; i < url_count % THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    print_sanitized_urls();
    
    // Free the original URL memory
    for (int i = 0; i < url_count; i++) {
        free(urls[i]);
    }
    
    pthread_mutex_destroy(&lock);
    
    return 0;
}