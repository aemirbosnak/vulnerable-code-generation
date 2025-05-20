//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define MAX_CHARS 10000

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char inputText[MAX_CHARS];
    int wordCount = 0, uniqueWords = 0;
    struct WordFrequency words[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", argv[1]);

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(inputText, MAX_CHARS, inputFile)!= NULL) {
        char *token = strtok(inputText, ",.?!;:");
        while (token!= NULL) {
            wordCount++;
            int i;
            for (i = 0; i < uniqueWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
            if (i == uniqueWords) {
                strcpy(words[uniqueWords].word, token);
                words[uniqueWords].frequency = 1;
                uniqueWords++;
                if (uniqueWords == MAX_WORDS) {
                    printf("Maximum number of unique words reached.\n");
                    break;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    printf("Total words: %d\n", wordCount);
    printf("Unique words: %d\n", uniqueWords);

    for (int i = 0; i < uniqueWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}