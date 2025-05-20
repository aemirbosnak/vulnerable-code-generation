//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount words[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        exit(1);
    }
    words[numWords].word = strdup(word);
    words[numWords].count = 1;
    numWords++;
}

void printWords(FILE *output) {
    int i;
    for (i = 0; i < numWords; i++) {
        fprintf(output, "%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char ch;
    int inWord = 0;
    char word[100];

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input);
        return 1;
    }

    while ((ch = fgetc(input))!= EOF) {
        if (isalnum(ch)) {
            inWord = 1;
            word[0] = tolower(ch);
            word[1] = '\0';
        } else if (inWord) {
            inWord = 0;
            addWord(word);
        }
    }

    if (inWord) {
        addWord(word);
    }

    fclose(input);
    fclose(output);

    printWords(output);

    return 0;
}