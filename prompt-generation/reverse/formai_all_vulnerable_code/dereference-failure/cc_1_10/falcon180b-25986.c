//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, WordFrequency *words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[words[i].count++] = tolower(ch);
        } else if (words[i].count > 0) {
            words[i].word[words[i].count] = '\0';
            i++;
            if (i >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(1);
            }
        }
    }
}

void countWords(WordFrequency *words, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    WordFrequency words[MAX_WORDS];
    FILE *file;
    char filename[50];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int numWords = 0;
    readFile(file, words);
    fclose(file);

    countWords(words, numWords);

    return 0;
}