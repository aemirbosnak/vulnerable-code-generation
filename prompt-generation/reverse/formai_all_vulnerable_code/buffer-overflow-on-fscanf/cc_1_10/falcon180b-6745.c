//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} Word;

int compareWords(const void* a, const void* b) {
    const Word* w1 = a;
    const Word* w2 = b;
    return strcmp(w1->word, w2->word);
}

void readWords(FILE* file, Word words[]) {
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS &&!found; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].freq++;
                found = 1;
            }
        }
        if (!found) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].freq = 1;
        }
    }
}

void writeWords(FILE* file, Word words[]) {
    qsort(words, MAX_WORDS, sizeof(Word), compareWords);
    for (int i = 0; i < MAX_WORDS; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].freq);
    }
}

int main() {
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    Word words[MAX_WORDS];
    readWords(input, words);
    fclose(input);

    FILE* output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    writeWords(output, words);
    fclose(output);

    return 0;
}