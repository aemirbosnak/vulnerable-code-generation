//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_WORD_COUNT 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: Please provide a file name as an argument.\n");
        return 1;
    }

    char fileName[MAX_FILE_NAME_LENGTH];
    strcpy(fileName, argv[1]);

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", fileName);
        return 1;
    }

    WordCount wordCounts[MAX_WORD_COUNT];
    int numWordCounts = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int lineLength = strlen(line);
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            line[--lineLength] = '\0';
        }

        char* word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int wordLength = strlen(word);
            if (wordLength > 0 && isalpha(word[0])) {
                word[wordLength - 1] = '\0';
                for (int i = 0; i < strlen(word); i++) {
                    word[i] = tolower(word[i]);
                }

                int index = 0;
                while (index < numWordCounts && strcmp(wordCounts[index].word, word)!= 0) {
                    index++;
                }

                if (index == numWordCounts) {
                    if (numWordCounts == MAX_WORD_COUNT) {
                        printf("Warning: Maximum number of word counts reached.\n");
                        break;
                    }
                    strcpy(wordCounts[numWordCounts].word, word);
                    wordCounts[numWordCounts].count = 1;
                    numWordCounts++;
                } else {
                    wordCounts[index].count++;
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word Count:\n");
    for (int i = 0; i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}