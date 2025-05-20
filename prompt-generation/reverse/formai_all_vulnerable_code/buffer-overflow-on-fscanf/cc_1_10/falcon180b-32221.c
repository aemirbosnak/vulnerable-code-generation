//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char word[MAX_SIZE];
    int count;
} Word;

void readWords(char *filename, Word *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_SIZE];
    int count = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_SIZE) {
            printf("Error: Too many words in file %s\n", filename);
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 1;
        count++;
    }

    fclose(file);
}

void searchWords(char *filename, Word *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        int found = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Error: Word %s not found in file %s\n", word, filename);
        }
    }

    fclose(file);
}

void printWords(Word *words) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./program input_file output_file\n");
        exit(1);
    }

    Word words[MAX_SIZE];
    readWords(argv[1], words);
    searchWords(argv[1], words);
    printWords(words);

    return 0;
}