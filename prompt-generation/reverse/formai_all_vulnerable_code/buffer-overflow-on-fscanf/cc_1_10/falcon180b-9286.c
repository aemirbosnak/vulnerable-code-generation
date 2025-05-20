//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_NUM_WORDS 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void readWords(FILE *file, WordCount *words) {
    char word[MAX_WORD_SIZE];
    int count = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_NUM_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 0;
        count++;
    }
}

void buildIndex(FILE *file, WordCount *words) {
    char word[MAX_WORD_SIZE];
    int count = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_NUM_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        count++;
    }
    for (int i = 0; i < count; i++) {
        words[i].count = 0;
    }
    rewind(file);
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < count; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
    }
}

void printIndex(WordCount *words) {
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char word[MAX_WORD_SIZE];
    strcpy(word, argv[2]);
    WordCount words[MAX_NUM_WORDS];
    readWords(file, words);
    buildIndex(file, words);
    printIndex(words);
    fclose(file);
    return 0;
}