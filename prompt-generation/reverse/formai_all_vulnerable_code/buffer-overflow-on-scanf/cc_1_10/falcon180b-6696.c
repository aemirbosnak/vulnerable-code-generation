//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void readFile(char *filename, struct Word *wordArray, int *numWords) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'!\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (i >= MAX_NUM_WORDS) {
                printf("Error: Too many words in the file!\n");
                exit(1);
            }
            strcpy(wordArray[i].word, word);
            wordArray[i].count = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
    *numWords = i;
}

void sortWords(struct Word *wordArray, int numWords) {
    int i, j;
    struct Word temp;

    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (strcmp(wordArray[i].word, wordArray[j].word) > 0) {
                temp = wordArray[i];
                wordArray[i] = wordArray[j];
                wordArray[j] = temp;
            }
        }
    }
}

void printWordCounts(struct Word *wordArray, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordArray[i].word, wordArray[i].count);
    }
}

int main(int argc, char *argv[]) {
    char filename[MAX_WORD_LENGTH];
    struct Word wordArray[MAX_NUM_WORDS];
    int numWords;

    printf("Enter the name of the file to be read: ");
    scanf("%s", filename);

    readFile(filename, wordArray, &numWords);
    sortWords(wordArray, numWords);
    printWordCounts(wordArray, numWords);

    return 0;
}