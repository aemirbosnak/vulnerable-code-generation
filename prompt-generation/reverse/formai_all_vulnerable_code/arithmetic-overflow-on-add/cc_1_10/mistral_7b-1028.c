//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 10000
#define WORD_LENGTH 50

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    if (c == ' ' || c == '\t' || c == ',' || c == '.' || c == ';' || c == ':' || c == '!' || c == '?' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
        return 1;
    return 0;
}

void countWords(char str[], int wordCount[], int *numWords) {
    int currentWord[WORD_LENGTH];
    int currentWordIndex = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            if (currentWordIndex > 0) {
                wordCount[*numWords]++;
                *numWords += 1;
                currentWordIndex = 0;
            }
            inWord = 0;
            continue;
        }

        if (!inWord) {
            currentWord[currentWordIndex++] = str[i];
            inWord = 1;
        }

        if (currentWordIndex >= WORD_LENGTH) {
            fprintf(stderr, "Word length exceeded!\n");
            exit(1);
        }
    }

    if (currentWordIndex > 0) {
        wordCount[*numWords]++;
        *numWords += 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file.");
        exit(1);
    }

    char str[MAX_CHAR];
    int wordCount[1000];
    int numWords = 0;

    while (fgets(str, MAX_CHAR, file) != NULL) {
        toLowerCase(str);
        countWords(str, wordCount, &numWords);
    }

    fclose(file);

    printf("Word count for the file %s:\n", argv[1]);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", (i == 0) ? "Total" : "", wordCount[i]);
    }

    return 0;
}