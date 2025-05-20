//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define WORD_COUNT 100

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

void toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int main() {
    FILE *fp;
    char filename[100];
    char line[1024];
    int wordIndex = 0;
    Word words[WORD_COUNT];

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            toLowerCase(token);
            int wordExists = 0;

            for (int i = 0; i < wordIndex; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    wordExists = 1;
                    break;
                }
            }

            if (!wordExists) {
                strcpy(words[wordIndex].word, token);
                words[wordIndex].count = 1;
                wordIndex++;
            }

            token = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);

    printf("\nWord Frequency Counter:\n");
    for (int i = 0; i < wordIndex; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}