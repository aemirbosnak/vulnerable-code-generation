//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 10

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    char text[MAX_WORDS][WORD_LENGTH];
    int numWords = 0;
    int i = 0;
    int j = 0;
    char word[WORD_LENGTH];
    WordFrequency frequencyTable[MAX_WORDS];

    // Read in the text file
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Count the number of words in the text file
    while (fscanf(file, "%s", word)!= EOF) {
        numWords++;
    }

    // Read in the words
    rewind(file);
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(text[i], word);
        i++;
    }

    // Create the frequency table
    for (i = 0; i < numWords; i++) {
        frequencyTable[i].word[0] = '\0';
        frequencyTable[i].frequency = 0;
    }

    for (i = 0; i < numWords; i++) {
        for (j = 0; j < numWords; j++) {
            if (strcmp(text[i], text[j]) == 0) {
                frequencyTable[i].frequency++;
            }
        }
    }

    // Print the frequency table
    for (i = 0; i < numWords; i++) {
        if (frequencyTable[i].frequency > 0) {
            printf("%s: %d\n", frequencyTable[i].word, frequencyTable[i].frequency);
        }
    }

    return 0;
}