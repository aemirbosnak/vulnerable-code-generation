//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency *wordFrequency = (WordFrequency*)malloc(MAX_WORDS * sizeof(WordFrequency));

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            int wordIndex = 0;
            while (wordFrequency[wordIndex].frequency > 0) {
                wordIndex++;
            }
            strcpy(wordFrequency[wordIndex].word, word);
            wordFrequency[wordIndex].frequency++;
            numWords++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Total number of words: %d\n", numWords);

    for (int i = 0; i < numWords; i++) {
        if (wordFrequency[i].frequency > 0) {
            printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
        }
    }

    free(wordFrequency);
    return 0;
}