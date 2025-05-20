//Falcon-180B DATASET v1.0 Category: Text processing ; Style: rigorous
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

void readFile(FILE *file, char *text) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        text[i++] = ch;
    }

    text[i] = '\0';
}

void tokenize(char *text, char delimiter, WordCount words[]) {
    char *token = strtok(text, delimiter);
    int i = 0;

    while (token!= NULL) {
        strcpy(words[i].word, token);
        words[i].count = 1;
        i++;

        token = strtok(NULL, delimiter);
    }
}

void printWords(WordCount words[], int numWords) {
    printf("Word\tCount\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    char text[MAX_WORDS * MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readFile(file, text);
    fclose(file);

    printf("Enter delimiter: ");
    scanf(" %c", &text[strcspn(text, "\n")]);

    tokenize(text, text[strcspn(text, "\n")], words);

    printWords(words, numWords);

    return 0;
}