//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_WORDS 100

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct word_count {
    char word[MAX_WORDS];
    int count;
};

void *count_words(void *arg) {
    FILE *fp = (FILE *) arg;
    struct word_count wc[MAX_WORDS];
    int i = 0;

    // Initialize all word counts to zero
    for (i = 0; i < MAX_WORDS; i++) {
        wc[i].count = 0;
    }

    // Read words from file and update their counts
    char word[MAX_WORDS];
    while (fscanf(fp, "%s", word)!= EOF) {
        pthread_mutex_lock(&mutex);
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(word, wc[j].word) == 0) {
                wc[j].count++;
                break;
            }
        }
        if (j == i) {
            strcpy(wc[i].word, word);
            wc[i].count = 1;
            i++;
        }
        pthread_mutex_unlock(&mutex);
    }

    // Print the word counts
    for (i = 0; i < MAX_WORDS; i++) {
        if (wc[i].count > 0) {
            printf("%s: %d\n", wc[i].word, wc[i].count);
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_WORDS];
    FILE *fp;
    char filename[100];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    // Open the input file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Create threads for counting words
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        pthread_create(&threads[i], NULL, count_words, (void *) fp);
    }

    // Join with all threads
    for (i = 0; i < MAX_WORDS; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}