//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = hash(word);
        if (index >= MAX_WORDS) {
            printf("Hash table overflow\n");
            exit(1);
        }
        words[index].count++;
    }

    fclose(file);
}

int hash(char* word) {
    int sum = 0;
    while (*word) {
        sum += *word;
        word++;
    }
    return sum % MAX_WORDS;
}

void printWords(WordCount* words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%d: %s\n", words[i].count, words[i].word);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    WordCount words[MAX_WORDS];
    loadWords(filename, words);

    printf("Word count:\n");
    printWords(words);

    return 0;
}