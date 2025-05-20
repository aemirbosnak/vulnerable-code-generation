//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to be executed by threads
void *count_words(void *arg) {
    char *str = (char *) arg;
    int count = 0;

    // Lock the mutex before accessing shared data
    pthread_mutex_lock(&mutex);

    // Count the number of words in the string
    char *word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    // Unlock the mutex after accessing shared data
    pthread_mutex_unlock(&mutex);

    // Return the result
    return (void *) count;
}

int main() {
    int num_threads, i;
    pthread_t threads[10];
    char input_string[100];

    // Get user input
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Get the number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, count_words, (void *) input_string);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the result
    printf("Number of words: %d\n", *(int *) input_string);

    return 0;
}