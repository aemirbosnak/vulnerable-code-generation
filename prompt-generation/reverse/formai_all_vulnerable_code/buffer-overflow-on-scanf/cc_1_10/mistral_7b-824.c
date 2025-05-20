//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define WORD_FREQ_TABLE_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void toLowerCase(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i]))
            str[i] = tolower(str[i]);
    }
}

int main() {
    FILE *file;
    char filename[100], line[1024], *token;
    WordFreq wordFreqTable[WORD_FREQ_TABLE_SIZE];

    printf("-----------------------------------------------------\n");
    printf("|                 HappyDataMiner                     |\n");
    printf("|---------------------------------------------------|\n");
    printf("|  A simple and happy C data mining program           |\n");
    printf("|  to find the most frequent word in a text file      |\n");
    printf("-----------------------------------------------------\n\n");

    printf("Enter the text file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        return 1;
    }

    int numWords = 0;
    while (fgets(line, sizeof(line), file)) {
        toLowerCase(line);
        token = strtok(line, " ,.-;:!?(){}[]");

        int i;
        for (i = 0; i < WORD_FREQ_TABLE_SIZE && strcmp(wordFreqTable[i].word, token); i++) {
            // If the word is not in the table, add it
            if (i == WORD_FREQ_TABLE_SIZE - 1) {
                strcpy(wordFreqTable[numWords].word, token);
                numWords++;
                wordFreqTable[numWords].count = 1;
                break;
            }
        }

        if (i < WORD_FREQ_TABLE_SIZE) {
            // If the word is already in the table, increment its count
            wordFreqTable[i].count++;
        }
    }

    fclose(file);

    // Find the most frequent word
    int mostFrequentIndex = 0;
    int maxCount = 0;

    for (int i = 0; i < numWords; i++) {
        if (wordFreqTable[i].count > maxCount) {
            maxCount = wordFreqTable[i].count;
            mostFrequentIndex = i;
        }
    }

    printf("\n-----------------------------------------------------\n");
    printf("|                 HappyEnding                         |\n");
    printf("-----------------------------------------------------\n\n");

    printf("The most frequent word in the text file is: %s\n", wordFreqTable[mostFrequentIndex].word);
    printf("It appeared %d times.\n", wordFreqTable[mostFrequentIndex].count);

    return 0;
}