//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 10

// Define the maximum number of characters in the pattern
#define MAX_PATTERN_LENGTH 100

// Define the pattern to be printed
char pattern[MAX_PATTERN_LENGTH];

// Define the number of characters in the pattern
int pattern_length;

// Define the number of characters each thread should print
int thread_pattern_length;

// Define the mutex for thread synchronization
pthread_mutex_t mutex;

// Define the thread ID for each thread
pthread_t threads[NUM_THREADS];

// Define the thread function
void *print_pattern(void *arg) {
    int i;
    int start_index;

    // Get the thread ID
    int thread_id = *(int *) arg;

    // Calculate the starting index for this thread
    start_index = thread_id * thread_pattern_length;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Print the pattern
    for (i = start_index; i < start_index + thread_pattern_length; i++) {
        printf("%c", pattern[i]);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(0);
}

// Define the main function
int main() {
    int i;
    char input[MAX_PATTERN_LENGTH];

    // Prompt the user for the pattern
    printf("Enter the pattern to be printed: ");
    scanf("%s", input);

    // Copy the pattern to the pattern array
    strcpy(pattern, input);

    // Calculate the length of the pattern
    pattern_length = strlen(pattern);

    // Calculate the number of characters each thread should print
    thread_pattern_length = pattern_length / NUM_THREADS;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, print_pattern, (void *) &i);
    }

    // Join the threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Exit the program
    return 0;
}