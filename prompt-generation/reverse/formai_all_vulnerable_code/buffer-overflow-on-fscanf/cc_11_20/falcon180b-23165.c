//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    WordFrequency words[MAX_NUM_WORDS];
    int numWords = 0;
    int i;

    // Open the input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the input file and count the frequency of each word
    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // Remove trailing newline character
        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, inputBuffer) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: Too many unique words.\n");
                fclose(inputFile);
                return 1;
            }
            strcpy(words[numWords].word, inputBuffer);
            words[numWords].frequency = 1;
            numWords++;
        }
    }

    // Sort the words by frequency in descending order
    for (i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the sorted list of words and their frequencies
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    // Close the input file
    fclose(inputFile);

    return 0;
}