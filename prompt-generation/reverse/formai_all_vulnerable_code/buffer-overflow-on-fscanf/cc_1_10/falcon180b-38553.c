//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void *countWords(void *arg) {
    FILE *file = (FILE *) arg;
    char word[MAX_WORD_LENGTH];
    int frequency = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        frequency++;
    }

    pthread_exit((void *) &frequency);
}

int compareWords(const void *a, const void *b) {
    const WordFrequency *w1 = (const WordFrequency *) a;
    const WordFrequency *w2 = (const WordFrequency *) b;

    return strcmp(w1->word, w2->word);
}

void printTopWords(WordFrequency words[], int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Top Words:\n");
    for (int i = 0; i < numWords && i < 10; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    pthread_t threads[MAX_WORDS];

    while (numWords < MAX_WORDS && fscanf(file, "%s", words[numWords].word)!= EOF) {
        pthread_create(&threads[numWords], NULL, countWords, file);
        numWords++;
    }

    for (int i = 0; i < numWords; i++) {
        pthread_join(threads[i], (void **) &words[i].frequency);
    }

    fclose(file);

    printTopWords(words, numWords);

    return 0;
}