//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS 4
#define NWORDS 10

// Structure to hold a word and its status (not yet processed or processed)
typedef struct {
    char *word;
    int status;
} word_t;

// Array to hold words and their statuses
word_t words[NWORDS];

// Semaphore to synchronize access to words array
sem_t sem;

// Function to initialize the words array and semaphore
void init() {
    int i;
    for (i = 0; i < NWORDS; i++) {
        words[i].word = malloc(10 * sizeof(char));
        words[i].status = 0;
    }
    sem_init(&sem, 0, NWORDS);
}

// Function to process a word asynchronously
void *process_word(void *word) {
    char *w = word;
    printf("Processing word: %s\n", w);
    // Simulate a long-running operation
    sleep(1);
    words[*((int *)word)].status = 1;
    return NULL;
}

// Function to main function
int main() {
    init();
    pthread_t threads[NTHREADS];
    int i;

    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&threads[i], NULL, process_word, (void *)&words[i]);
    }

    // Wait for all threads to finish
    sem_wait(&sem);

    // Print the processed words
    for (i = 0; i < NWORDS; i++) {
        if (words[i].status == 1) {
            printf("%d: %s\n", i, words[i].word);
        }
    }

    return 0;
}