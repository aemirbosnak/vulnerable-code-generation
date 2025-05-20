//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

bool compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b) < 0;
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    Word words[MAX_WORDS];
    int numWords = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char* word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Reached maximum number of words.\n");
                break;
            }
            Word* w = &words[numWords++];
            strcpy(w->word, word);
            w->count = 1;
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}