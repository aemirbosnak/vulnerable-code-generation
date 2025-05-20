//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(char *filename, WordCount *wordCounts) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (i == MAX_WORDS) {
                if (wordCounts[0].word[0] == '\0') {
                    strcpy(wordCounts[0].word, word);
                } else {
                    printf("Error: Too many unique words in file\n");
                    exit(1);
                }
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void printWordCounts(WordCount *wordCounts) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].word[0]!= '\0') {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    WordCount wordCounts[MAX_WORDS];

    loadWords(filename, wordCounts);
    printWordCounts(wordCounts);

    return 0;
}