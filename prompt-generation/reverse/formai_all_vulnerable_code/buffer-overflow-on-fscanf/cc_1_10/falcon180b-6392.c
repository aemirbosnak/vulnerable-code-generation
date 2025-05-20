//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

int getWordCount(FILE* file, WordCount* wordCounts, int count) {
    char word[MAX_WORD_LENGTH];
    char* token;
    int i;

    while ((fscanf(file, "%s", word))!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        token = strtok(word, " ");
        while (token!= NULL) {
            i = 0;
            while (i < count && strcmp(wordCounts[i].word, token)!= 0) {
                i++;
            }
            if (i == count) {
                wordCounts[count - 1].word[0] = '\0';
                count++;
                memmove(wordCounts + 1, wordCounts, count - 1);
                wordCounts[0] = (WordCount){.word = token,.count = 1};
            } else {
                wordCounts[i].count++;
            }
            token = strtok(NULL, " ");
        }
    }

    qsort(wordCounts, count, sizeof(WordCount), compareWords);

    return count;
}

int main() {
    FILE* file;
    WordCount wordCounts[MAX_WORD_LENGTH];
    int count = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    count = getWordCount(file, wordCounts, count);

    printf("Word Count:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(file);
    return 0;
}