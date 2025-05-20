//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

// Struct to store each word along with its frequency
typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structs based on frequency
int compare(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read the input file and count the frequency of each word
void countWords(FILE *inputFile, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LEN];
    int wordIndex = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character from end of word

        int i;
        for (i = 0; i < wordIndex; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                break;
            }
        }

        if (i == wordIndex) {
            strcpy(words[wordIndex].word, word);
            words[wordIndex].frequency = 1;
            wordIndex++;
        }
    }
}

// Function to sort the words based on frequency
void sortWords(WordFrequency words[MAX_WORDS]) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compare);
}

// Function to print the top 10 most frequent words
void printTopWords(WordFrequency words[MAX_WORDS]) {
    printf("Top 10 most frequent words:\n");
    int i;
    for (i = 0; i < 10 && i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *inputFile;
    WordFrequency words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    countWords(inputFile, words);
    sortWords(words);
    printTopWords(words);

    fclose(inputFile);
    return 0;
}