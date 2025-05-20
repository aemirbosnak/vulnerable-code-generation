//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_SENTENCES 100

struct thread_data {
    int thread_id;
    char *sentence;
    int num_spam_words;
};

void *detect_spam(void *data) {
    struct thread_data *thread_data = (struct thread_data *) data;
    char *sentence = thread_data->sentence;
    int num_spam_words = thread_data->num_spam_words;

    int num_spam_words_found = 0;
    char *spam_words[50];

    // Detect spam words in the sentence
    for (int i = 0; i < num_spam_words; i++) {
        spam_words[i] = strtok(sentence, " ");
        while (spam_words[i]!= NULL) {
            if (strstr(spam_words[i], "spam")!= NULL) {
                num_spam_words_found++;
            }
            i++;
        }
    }

    pthread_exit(NULL);
}

int main() {
    struct thread_data thread_data[MAX_THREADS];
    int num_spam_words[MAX_THREADS];
    int thread_count = 0;

    FILE *file = fopen("spam.txt", "r");
    char sentence[MAX_SENTENCES][100];
    char *spam_words[50];

    // Read sentences from the file
    while (fscanf(file, "%s", sentence[thread_count])!= EOF) {
        thread_data[thread_count].thread_id = thread_count;
        thread_data[thread_count].sentence = sentence[thread_count];
        thread_data[thread_count].num_spam_words = 0;

        num_spam_words[thread_count] = 0;
        thread_count++;

        if (thread_count >= MAX_THREADS) {
            thread_count = 0;
        }
    }

    // Start the threads
    for (int i = 0; i < thread_count; i++) {
        pthread_create(&thread_data[i].thread_id, NULL, detect_spam, (void *) &thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(thread_data[i].thread_id, NULL);
    }

    // Print the number of spam words found in each sentence
    for (int i = 0; i < thread_count; i++) {
        printf("%d - %d\n", i, num_spam_words[i]);
    }

    return 0;
}