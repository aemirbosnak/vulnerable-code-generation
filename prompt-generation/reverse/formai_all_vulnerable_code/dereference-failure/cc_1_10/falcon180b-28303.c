//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_WORDS 1000
#define MAX_CHARS 100

struct data {
    char word[MAX_CHARS];
    int count;
};

void *count_words(void *arg) {
    char *sentence = (char *) arg;
    struct data *words = (struct data *) malloc(MAX_WORDS * sizeof(struct data));
    int num_words = 0;

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in sentence.\n");
            exit(1);
        }
        strcpy(words[num_words].word, token);
        words[num_words].count = 1;
        num_words++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    free(words);
    return NULL;
}

int main() {
    char sentence[MAX_CHARS];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_CHARS, stdin);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, count_words, sentence);

    pthread_join(thread_id, NULL);

    return 0;
}