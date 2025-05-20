//Falcon-180B DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* file;
    char line[MAX_WORD_LENGTH + 1];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char* word = strtok(line, " ");

        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Too many words in file.\n");
                exit(2);
            }

            WordCount* newWord = &words[numWords];
            strcpy(newWord->word, word);
            newWord->count = 1;

            WordCount* existingWord = bsearch(newWord, words, numWords, sizeof(WordCount), compareWords);

            if (existingWord == NULL) {
                numWords++;
            } else {
                existingWord->count++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}