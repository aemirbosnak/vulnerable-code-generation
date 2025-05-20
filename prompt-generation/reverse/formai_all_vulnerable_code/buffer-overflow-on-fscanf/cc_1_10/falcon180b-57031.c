//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *f, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(f, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].count = 1;
        }
    }
}

void writeWords(FILE *f, WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(f, "%s %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *f;
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    WordCount words[MAX_WORDS];
    readWords(f, words);
    fclose(f);

    f = fopen("output.txt", "w");
    if (f == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    writeWords(f, words);
    fclose(f);

    return 0;
}