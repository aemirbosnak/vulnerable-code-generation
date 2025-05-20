//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_TOKENS 1000
#define MAX_WORD_LEN 10
#define NUM_THREADS 4

typedef struct {
    char *word;
    int is_spam;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void *spam_detection_thread(void *arg) {
    int i;
    int num_spam_words = 0;

    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].is_spam) {
            num_spam_words++;
        }
    }

    if (num_spam_words > 0) {
        printf("Thread %d detected spam.\n", (int) arg);
    } else {
        printf("Thread %d did not detect spam.\n", (int) arg);
    }

    return NULL;
}

int main() {
    FILE *fp;
    char line[1024];
    char word[MAX_WORD_LEN + 1];
    int i, j, is_spam;

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open spam_words.txt\n");
        exit(1);
    }

    i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        tokens[i].word = strdup(word);
        tokens[i].is_spam = 1;
        i++;
        num_tokens++;
    }

    fclose(fp);

    pthread_t threads[NUM_THREADS];

    for (j = 0; j < NUM_THREADS; j++) {
        pthread_create(&threads[j], NULL, spam_detection_thread, (void *) j);
    }

    for (j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}