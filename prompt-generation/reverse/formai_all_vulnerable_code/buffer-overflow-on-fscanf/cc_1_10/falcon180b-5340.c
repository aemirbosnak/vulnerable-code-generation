//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *file, WordFrequency *words, int *numWords) {
    char word[MAX_WORD_LENGTH];
    int wordLength;

    while (fscanf(file, "%s", word)!= EOF) {
        wordLength = strlen(word);

        if (*numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }

        strncpy(words[*numWords].word, word, wordLength);
        words[*numWords].word[wordLength] = '\0';
        words[*numWords].frequency = 1;
        (*numWords)++;
    }
}

void printWordFrequencies(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    readWords(file, words, &numWords);

    fclose(file);

    printf("\nWord frequencies:\n");
    printWordFrequencies(words, numWords);

    return 0;
}