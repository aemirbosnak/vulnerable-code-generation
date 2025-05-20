//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadDictionary(char* filename, WordCount words[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Error: word %s is too long\n", word);
            exit(1);
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }
    }

    fclose(fp);
}

void checkSpelling(char* filename, WordCount words[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Error: word %s is too long\n", word);
            exit(1);
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                printf("%s: %d\n", word, words[j].count);
                break;
            }
        }
    }

    fclose(fp);
}

int main() {
    char dictfilename[100];
    printf("Enter dictionary filename: ");
    scanf("%s", dictfilename);

    WordCount words[MAX_WORDS];
    loadDictionary(dictfilename, words);

    char filename[100];
    printf("Enter filename to check: ");
    scanf("%s", filename);

    checkSpelling(filename, words);

    return 0;
}