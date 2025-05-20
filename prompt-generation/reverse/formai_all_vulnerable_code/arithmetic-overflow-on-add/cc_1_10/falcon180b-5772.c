//Falcon-180B DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(char *filename, WordCount words[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[j].word, word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }

    fclose(fp);
}

void printWords(WordCount words[], int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    readWords(filename, words);

    int numWords = 0;
    while (numWords < MAX_WORDS && strlen(words[numWords].word) > 0) {
        numWords++;
    }

    printWords(words, numWords);

    return 0;
}