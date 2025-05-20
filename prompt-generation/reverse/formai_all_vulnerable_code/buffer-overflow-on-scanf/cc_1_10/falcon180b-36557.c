//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int numWords;
} Text;

void addWord(Text *text, char *word) {
    int i;
    for (i = 0; i < text->numWords; i++) {
        if (strcmp(text->words[i].word, word) == 0) {
            text->words[i].count++;
            return;
        }
    }
    if (text->numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words exceeded.\n");
        exit(1);
    }
    strcpy(text->words[text->numWords].word, word);
    text->words[text->numWords].count = 1;
    text->numWords++;
}

void printWords(Text *text) {
    int i;
    for (i = 0; i < text->numWords; i++) {
        printf("%s: %d\n", text->words[i].word, text->words[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    Text text = {0};
    char word[MAX_WORD_LENGTH];
    char *token;
    while ((token = strtok(NULL, " \t\n\r\f\v"))!= NULL) {
        strcpy(word, token);
        addWord(&text, word);
    }

    fclose(file);

    printf("The frequency of words in the file is:\n");
    printWords(&text);

    return 0;
}