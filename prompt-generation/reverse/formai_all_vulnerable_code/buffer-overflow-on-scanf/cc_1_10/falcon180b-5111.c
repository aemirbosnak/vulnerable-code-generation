//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void initWords(struct Word *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].count = 0;
    }
}

int compareWords(const void *a, const void *b) {
    struct Word *wordA = (struct Word *)a;
    struct Word *wordB = (struct Word *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *fp, struct Word *words) {
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int len = strlen(word);
            if (len > MAX_WORD_LENGTH) {
                len = MAX_WORD_LENGTH;
            }
            strncpy(words[hash(word)].word, word, len);
            words[hash(word)].count++;
            word = strtok(NULL, ",.?!;:");
        }
    }
}

int hash(char *word) {
    int hash = 0;
    while (*word) {
        hash = (hash * 31) ^ (*word - 'a');
        word++;
    }
    return hash % MAX_WORDS;
}

void printWords(struct Word *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    struct Word words[MAX_WORDS];
    initWords(words);
    readWords(fp, words);

    fclose(fp);

    qsort(words, MAX_WORDS, sizeof(struct Word), compareWords);

    printf("\nWord count:\n");
    printWords(words);

    return 0;
}