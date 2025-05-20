//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readBook(char *filename, WordFrequency *wordFrequencies) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    char *token;
    int wordCount = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, ".,!?;:")] = '\0';
        word[strcspn(word, "0123456789")] = '\0';
        wordCount++;

        token = strtok(word, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(token, wordFrequencies[i].word) == 0) {
                    wordFrequencies[i].count++;
                    break;
                }
            }

            if (i == MAX_WORDS) {
                if (wordCount >= MAX_WORDS) {
                    printf("Reached maximum number of words.\n");
                    break;
                }

                strcpy(wordFrequencies[wordCount].word, token);
                wordFrequencies[wordCount].count = 1;
                wordCount++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        if (wordFrequencies[i].count > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    readBook(argv[1], wordFrequencies);
    printWordFrequencies(wordFrequencies, wordFrequencies[0].count);

    return 0;
}