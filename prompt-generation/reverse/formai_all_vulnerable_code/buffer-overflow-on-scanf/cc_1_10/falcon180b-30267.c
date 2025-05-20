//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_WORDS 1000
#define MAX_THREADS 10

typedef struct {
    char word[50];
    char translation[100];
} WordTranslation;

void *translateWords(void *arg) {
    int i;
    char *word;
    WordTranslation *translation = (WordTranslation *) arg;

    for (i = 0; i < MAX_WORDS; i++) {
        word = (char *) malloc(50 * sizeof(char));
        strcpy(word, translation->word);
        printf("Translating word %s...\n", word);
        sleep(1);
        free(word);
    }

    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];
    WordTranslation translations[MAX_WORDS];

    for (i = 0; i < MAX_WORDS; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", translations[i].word);
        strcpy(translations[i].translation, "Alien Language");
    }

    for (i = 0; i < MAX_THREADS; i++) {
        for (j = 0; j < MAX_WORDS; j += MAX_WORDS / MAX_THREADS) {
            pthread_create(&threads[i], NULL, translateWords, &translations[j]);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}