//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_LEN 100

// Global variables
char message[MAX_LEN];
char encrypted_message[MAX_LEN];
int key;
int message_len;
pthread_mutex_t mutex; // Mutex to lock access to message and encrypted_message 

// Worker thread function
void *worker_thread(void *ptr) {
    int thread_num = *(int *)ptr;
    int start = thread_num * (message_len / MAX_THREADS);
    int end = (thread_num == MAX_THREADS - 1) ? message_len : (thread_num + 1) * (message_len / MAX_THREADS);
    char *p = message + start;
    char *q = encrypted_message + start;
    
    // Encrypt the message using key
    for (int i = start; i < end; i++, p++, q++) {
        if (*p >= 'a' && *p <= 'z') {
            *q = 'a' + ((*p - 'a') + key) % 26;
        } else if (*p >= 'A' && *p <= 'Z') {
            *q = 'A' + ((*p - 'A') + key) % 26;
        } else {
            *q = *p;
        }
    }

    pthread_mutex_lock(&mutex);
    printf("Worker thread %d encrypted: %s\n", thread_num, encrypted_message + start);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t tid[MAX_THREADS];
    int thread_num[MAX_THREADS];

    // Input message and key
    printf("Enter a message: ");
    fgets(message, MAX_LEN, stdin);
    message_len = strlen(message);
    message[message_len - 1] = '\0';
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create worker threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_num[i] = i;
        pthread_create(&tid[i], NULL, worker_thread, &thread_num[i]);
    }

    // Join worker threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    printf("Encrypted message: %s\n", encrypted_message); // Print encrypted message

    return 0;
}