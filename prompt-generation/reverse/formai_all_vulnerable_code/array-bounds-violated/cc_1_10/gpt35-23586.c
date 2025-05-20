//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000
#define NUM_THREADS 10

char message[MAX_MSG_LENGTH] = "";
int watermark = 123456;

void *thread_function(void *args) {
    char *msg = (char*)args;
    int thread_watermark = watermark + pthread_self(); // Get unique watermark for thread
    int msg_len = strlen(msg);

    // Loop through message and add the watermark to each character
    for (int i = 0; i < msg_len; i++) {
        msg[i] += thread_watermark;
    }

    printf("Thread ID %ld: Watermarked message: %s\n", pthread_self(), msg);
    return NULL;
}

int main() {
    // Get input message from user
    printf("Enter a message to watermark: ");
    fgets(message, MAX_MSG_LENGTH, stdin);

    // Remove newline character at end of input
    int msg_len = strlen(message);
    if (message[msg_len-1] == '\n') {
        message[msg_len-1] = '\0';
    }
    
    // Create threads to watermark message
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int res = pthread_create(&threads[i], NULL, thread_function, (void*)message);
        if (res != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}