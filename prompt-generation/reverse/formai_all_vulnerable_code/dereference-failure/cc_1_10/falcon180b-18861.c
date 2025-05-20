//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

void readFile(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    char *ptr = fgets(word, MAX_WORD_LENGTH, file);
    while (ptr!= NULL) {
        if (strcspn(word, " \n\t\r")!= strlen(word)) {
            word[strcspn(word, " \n\t\r")] = '\0';
            tolower(word);
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
                if (strcmp(words[i].word, "") == 0) {
                    strcpy(words[i].word, word);
                    words[i].count = 1;
                    break;
                }
            }
        }
        ptr = fgets(word, MAX_WORD_LENGTH, file);
    }
}

void printWords(WordCount words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    WordCount words[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        strcpy(words[i].word, "");
        words[i].count = 0;
    }
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    readFile(file, words);
    fclose(file);
    printWords(words);
    return 0;
}