//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

void loadWords(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = 0;
        while (index < MAX_WORDS && words[index].word[0]!= '\0') {
            index++;
        }
        if (index < MAX_WORDS) {
            strcpy(words[index].word, word);
            words[index].count = 1;
        } else {
            printf("Error: Maximum number of words exceeded.\n");
        }
    }
}

void sortWords(WordFrequency words[]) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);
}

int main() {
    FILE *file;
    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    loadWords(file, words);
    fclose(file);

    sortWords(words);

    printf("Word frequencies:\n");
    for (int i = 0; i < MAX_WORDS && words[i].word[0]!= '\0'; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}