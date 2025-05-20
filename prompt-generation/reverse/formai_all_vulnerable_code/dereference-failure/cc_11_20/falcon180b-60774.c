//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char **argv) {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    int i, j, wordCount = 0;
    struct Word *words = (struct Word *)malloc(MAX_WORDS * sizeof(struct Word));

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file. Exiting program.\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            // Check if word already exists in array
            for (i = 0; i < wordCount; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    // Increase count of existing word
                    words[i].count++;
                    break;
                }
            }
            // Add new word to array
            if (i == wordCount) {
                strcpy(words[wordCount].word, token);
                words[wordCount].count = 1;
                wordCount++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Close input file
    fclose(inputFile);

    // Sort words by frequency
    for (i = 0; i < wordCount - 1; i++) {
        for (j = i + 1; j < wordCount; j++) {
            if (words[j].count > words[i].count) {
                // Swap words and their counts
                struct Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print frequency of each word
    printf("Frequency of words:\n");
    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free memory
    free(words);

    return 0;
}