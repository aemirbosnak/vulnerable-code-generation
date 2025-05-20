//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Alan Turing
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the filename: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        numWords++;

        if (numWords > MAX_NUM_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        int wordLen = strlen(line);
        int isWord = 1;

        for (i = 0; i < wordLen; i++) {
            if (!isalnum(line[i])) {
                isWord = 0;
                break;
            }
        }

        if (isWord) {
            strcpy(words[numWords-1].word, line);
            words[numWords-1].count = 1;
        }
    }

    fclose(file);

    printf("Enter the word to count: ");
    scanf("%s", line);

    int wordFound = 0;
    int totalCount = 0;

    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, line) == 0) {
            wordFound = 1;
            totalCount += words[i].count;
        }
    }

    if (wordFound) {
        printf("The word '%s' appears %d times in the file.\n", line, totalCount);
    } else {
        printf("The word '%s' does not appear in the file.\n", line);
    }

    return 0;
}