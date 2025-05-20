//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: realistic
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Mutex to protect shared data
pthread_mutex_t lock;

// Condition variable to wait for data to be ready
pthread_cond_t cond;

// Shared data
int data = 0;

// Thread function
void *thread_func(void *arg) {
    // Lock the mutex
    pthread_mutex_lock(&lock);

    // Wait for data to be ready
    while (data == 0) {
        pthread_cond_wait(&cond, &lock);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&lock);

    // Do something with the data
    printf("Received data: %d\n", data);

    return NULL;
}

int main() {
    // Initialize the mutex and condition variable
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    // Create a thread
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    // Wait for the user to enter some data
    printf("Enter some data: ");
    scanf("%d", &data);

    // Lock the mutex
    pthread_mutex_lock(&lock);

    // Signal that data is ready
    pthread_cond_signal(&cond);

    // Unlock the mutex
    pthread_mutex_unlock(&lock);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}