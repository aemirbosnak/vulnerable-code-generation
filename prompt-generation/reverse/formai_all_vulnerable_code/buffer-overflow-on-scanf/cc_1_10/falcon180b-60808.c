//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[1000];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i, j;

    printf("Enter the name of the file: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                j = 0;
                while (isalpha(line[i + j]) && j < MAX_WORD_LENGTH - 1) {
                    j++;
                }
                strncpy(words[numWords].word, &line[i], j);
                words[numWords].word[j] = '\0';
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    fclose(file);

    printf("Enter the word to search for: ");
    scanf("%s", line);

    for (i = 0; i < numWords; i++) {
        if (strcmp(line, words[i].word) == 0) {
            printf("The word '%s' appears %d times.\n", words[i].word, words[i].count);
        }
    }

    return 0;
}