//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_THREADS 4

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Sentence to be analyzed
char sentence[MAX_SENTENCE_LENGTH];

// Word count
int word_count;

// Total number of positive, negative, and neutral words
int positive_count, negative_count, neutral_count;

// Array to store the results for each thread
int results[NUM_THREADS];

// Function to analyze the sentiment of a word
void *analyze_sentiment(void *arg) {
    char *word = (char *) arg;
    int sentiment = 0;

    // Analyze the sentiment of the word
    if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0) {
        sentiment = 1; // Positive
    } else if (strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0) {
        sentiment = -1; // Negative
    } else {
        sentiment = 0; // Neutral
    }

    // Update the results for this thread
    pthread_mutex_lock(&mutex);
    results[pthread_self()] = sentiment;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Function to split the sentence into words
void split_sentence() {
    char *token = strtok(sentence, " ");
    int i = 0;

    while (token!= NULL) {
        word_count++;

        // Create a thread to analyze the sentiment of this word
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, analyze_sentiment, token);

        // Wait for the thread to finish
        pthread_join(thread_id, NULL);

        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    // Prompt the user for a sentence
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Split the sentence into words
    split_sentence();

    // Print the results
    printf("Total word count: %d\n", word_count);
    printf("Positive words: %d\n", positive_count);
    printf("Negative words: %d\n", negative_count);
    printf("Neutral words: %d\n", neutral_count);

    return 0;
}