//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct Word {
    char word[MAX_WORD_LENGTH];
    int value;
};

struct Word words[MAX_WORDS];
int numWords = 0;

void addWord(char *word, int value) {
    if (numWords >= MAX_WORDS) {
        printf("Error: maximum number of words reached.\n");
        return;
    }
    strcpy(words[numWords].word, word);
    words[numWords].value = value;
    numWords++;
}

void loadWords() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        line[strcspn(line, "\n")] = 0;
        char *word = strtok(line, " ");
        int value = atoi(strtok(NULL, " "));
        addWord(word, value);
    }
    fclose(fp);
}

int main() {
    loadWords();
    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = 0;
        char *word = strtok(input, " ");
        int value = 0;
        struct Word *foundWord = NULL;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, word) == 0) {
                foundWord = &words[i];
                break;
            }
        }
        if (foundWord == NULL) {
            printf("Error: unknown word \"%s\".\n", word);
        } else {
            value = foundWord->value;
        }
        printf("The value of \"%s\" is %d.\n", word, value);
    }
    return 0;
}