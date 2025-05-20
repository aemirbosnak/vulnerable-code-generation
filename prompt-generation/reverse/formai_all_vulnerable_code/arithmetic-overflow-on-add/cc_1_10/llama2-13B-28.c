//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 4096

// Structure to store the words and their counts
typedef struct {
    char *word;
    int count;
} word_count_t;

// Function to count the words in a given string
void *count_words(void *arg) {
    // Cast the argument to a string
    char *str = (char *)arg;

    // Initialize the word count structure
    word_count_t *word_count = calloc(1, sizeof(word_count_t));

    // Iterate over the characters in the string
    for (size_t i = 0; i < strlen(str); i++) {
        // Check if the current character is a word boundary
        if (isspace(str[i])) {
            // If it is, increment the count for the previous word
            if (word_count->word != NULL) {
                word_count->count++;
            }

            // Reset the word count structure for the new word
            word_count = calloc(1, sizeof(word_count_t));
        }

        // If the current character is not a word boundary, add it to the current word
        else {
            word_count->word = realloc(word_count->word, strlen(word_count->word) + 1);
            word_count->word[strlen(word_count->word) - 1] = str[i];
        }
    }

    // If there are any words left in the current word count structure, increment their counts
    if (word_count->word != NULL) {
        word_count->count++;
    }

    // Return the word count structure
    return word_count;
}

// Function to print the word counts
void print_word_counts(word_count_t *word_counts) {
    // Iterate over the word counts
    for (size_t i = 0; i < sizeof(word_counts) / sizeof(word_counts[0]); i++) {
        printf("%d: %s\n", word_counts[i].count, word_counts[i].word);
    }
}

int main() {
    // Create a semaphore to synchronize the word count threads
    sem_t sem;
    sem_init(&sem, 0, 1);

    // Create an array of strings to count
    char *strings[] = {
        "The quick brown fox jumps over the lazy dog.",
        "The quick brown fox jumps over the lazy dog again.",
        "The quick brown fox jumps over the lazy dog repeatedly."
    };

    // Create an array of word count structures
    word_count_t *word_counts = calloc(sizeof(word_counts), sizeof(word_count_t));

    // Create a thread for each string to count the words
    for (size_t i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        pthread_t thread;
        sem_wait(&sem);

        // Pass the string to count to the thread function
        count_words(strings[i]);

        sem_post(&sem);
    }

    // Wait for all the threads to finish
    sem_wait(&sem);

    // Print the word counts
    print_word_counts(word_counts);

    return 0;
}