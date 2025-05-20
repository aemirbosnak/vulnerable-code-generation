//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char input[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    FILE *file;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i, j, k;

    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s", input)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            return 1;
        }

        for (i = 0; i < strlen(input); i++) {
            if (isalpha(input[i])) {
                input[i] = tolower(input[i]);
            } else {
                input[i] = '\0';
            }
        }

        for (j = 0; j < numWords; j++) {
            if (strcmp(input, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }

        if (j == numWords) {
            strcpy(words[numWords].word, input);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}