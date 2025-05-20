//Falcon-180B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct WordFrequency *CreateWordFrequencyArray(int numWords) {
    struct WordFrequency *array = (struct WordFrequency *)malloc(numWords * sizeof(struct WordFrequency));
    for (int i = 0; i < numWords; i++) {
        array[i].frequency = 0;
    }
    return array;
}

void ProcessWord(char *word, struct WordFrequency *array, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(array[i].word, word) == 0) {
            array[i].frequency++;
            return;
        }
    }
    for (i = 0; i < numWords; i++) {
        if (array[i].frequency == 0) {
            strcpy(array[i].word, word);
            array[i].frequency = 1;
            return;
        }
    }
}

void ReadWordsFromFile(char *filename, struct WordFrequency *array, int numWords) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    while (fscanf(file, "%s", word)!= EOF) {
        ProcessWord(word, array, numWords);
        i++;
    }
    fclose(file);
}

void SortWordFrequencyArray(struct WordFrequency *array, int numWords) {
    int i, j;
    struct WordFrequency temp;
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (array[i].frequency < array[j].frequency) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void PrintWordFrequencyArray(struct WordFrequency *array, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", array[i].word, array[i].frequency);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    struct WordFrequency *array = CreateWordFrequencyArray(MAX_WORDS);
    ReadWordsFromFile(filename, array, MAX_WORDS);
    SortWordFrequencyArray(array, MAX_WORDS);
    PrintWordFrequencyArray(array, MAX_WORDS);
    return 0;
}