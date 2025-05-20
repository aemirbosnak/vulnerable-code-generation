//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper((unsigned char)str[i]))
            str[i] += 32;
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int main() {
    FILE *file;
    Word words[MAX_WORDS];
    int numWords = 0;
    char line[1024], word[WORD_LENGTH];

    printf("What is the name of the input file?\n");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", line);
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        toLowerCase(line);
        char *token = strtok(line, " \n\t");
        while (token != NULL) {
            strcpy(word, token);
            int isWordFound = 0;

            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    isWordFound = 1;
                    break;
                }
            }

            if (!isWordFound) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, " \n\t");
        }
    }

    fclose(file);

    printf("\nWord Frequencies:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}