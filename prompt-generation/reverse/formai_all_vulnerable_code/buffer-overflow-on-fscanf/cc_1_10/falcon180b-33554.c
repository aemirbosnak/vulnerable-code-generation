//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void loadWords(Word words[]);
void shuffleWords(Word words[]);
void printWords(Word words[], int count);
int compareWords(const void *a, const void *b);

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    loadWords(words);
    shuffleWords(words);

    int count = 0;
    while (count < MAX_WORDS) {
        printf("Type the word %s:\n", words[count].word);
        fgets(words[count].word, MAX_WORD_LENGTH, stdin);
        words[count].length = strlen(words[count].word);
        count++;
    }

    qsort(words, MAX_WORDS, sizeof(Word), compareWords);

    printf("The results of the typing speed test:\n");
    printf("Total words: %d\n", MAX_WORDS);
    printf("Correct words: %d\n", count);
    printf("Accuracy: %.2f%%\n", (float)count / MAX_WORDS * 100);

    return 0;
}

void loadWords(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

void shuffleWords(Word words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        int j = rand() % MAX_WORDS;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void printWords(Word words[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%d characters)\n", words[i].word, words[i].length);
    }
}

int compareWords(const void *a, const void *b) {
    Word wordA = *(Word*)a;
    Word wordB = *(Word*)b;

    int result = strcmp(wordA.word, wordB.word);
    if (result == 0) {
        result = wordA.length - wordB.length;
    }

    return result;
}