//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
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
            if (j < MAX_WORDS) {
                strcpy(words[j].word, word);
                words[j].count = 1;
            }
        }
    }
}

void printWords(WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    WordCount words[MAX_WORDS];
    readWords(fp, words);
    fclose(fp);
    printf("Words and their frequencies:\n");
    printWords(words);
    return 0;
}