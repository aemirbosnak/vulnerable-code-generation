//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readTextFile(FILE *file, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        wordLength = strlen(word);

        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(wordFrequencies[i].word, word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }

            if (strcmp(wordFrequencies[MAX_WORDS - 1].word, "") == 0) {
                strcpy(wordFrequencies[MAX_WORDS - 1].word, word);
                wordFrequencies[MAX_WORDS - 1].frequency = 1;
            }
        }
    }
}

void displayTopNWords(WordFrequency *wordFrequencies, int n) {
    printf("Top %d most frequent words:\n", n);

    for (int i = 0; i < n && i < MAX_WORDS; i++) {
        if (strcmp(wordFrequencies[i].word, "")!= 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readTextFile(file, wordFrequencies);

    printf("Enter the number of top frequent words to display: ");
    int n;
    scanf("%d", &n);

    displayTopNWords(wordFrequencies, n);

    fclose(file);

    return 0;
}