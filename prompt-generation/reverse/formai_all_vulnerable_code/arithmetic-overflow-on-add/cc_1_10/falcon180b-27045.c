//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open the file
    file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in the words
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        numWords++;
        if (numWords > MAX_WORDS) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
        strcpy(word, line);
        for (i = 0; i < strlen(word); i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            } else {
                word[i] = '\0';
            }
        }
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].frequency = 1;
            numWords++;
        }
    }

    // Print out the word frequencies
    printf("Word frequencies:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    // Close the file
    fclose(file);

    return 0;
}