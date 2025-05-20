//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void loadWords(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF && count < MAX_WORDS) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

void randomizeWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int compareWords(const void *a, const void *b) {
    const Word *wordA = (const Word *)a;
    const Word *wordB = (const Word *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    loadWords(words);

    int numWords = rand() % MAX_WORDS;
    randomizeWords(words, numWords);

    printf("Type the following %d words:\n", numWords);
    printWords(words, numWords);

    int correctWords = 0;
    double timeTaken = 0.0;

    clock_t startTime = clock();
    for (int i = 0; i < numWords; i++) {
        char input[MAX_WORD_LENGTH];
        printf("Word %d: ", i+1);
        scanf("%s", input);

        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        }
    }

    clock_t endTime = clock();
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nYou typed %d out of %d words correctly in %.2f seconds.\n", correctWords, numWords, elapsedTime);

    return 0;
}