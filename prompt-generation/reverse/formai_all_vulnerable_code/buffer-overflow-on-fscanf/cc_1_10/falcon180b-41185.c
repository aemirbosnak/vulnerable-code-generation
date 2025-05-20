//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *word;
    int count;
} WordFrequency;

void read_words(char *filename, WordFrequency *words, int size) {
    FILE *file;
    char word[MAX_SIZE];
    char *token;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= size) {
            printf("Word frequency table is full.\n");
            break;
        }

        words[i].word = strdup(word);
        words[i].count = 0;
        i++;
    }

    fclose(file);
}

void count_words(char *filename, WordFrequency *words, int size) {
    FILE *file;
    char word[MAX_SIZE];
    char *token;
    int i, j;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        j = 0;
        while (j < size && strcmp(words[j].word, word)!= 0) {
            j++;
        }

        if (j == size) {
            printf("Word not found in table: %s\n", word);
            continue;
        }

        words[j].count++;
    }

    fclose(file);
}

void print_words(WordFrequency *words, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    WordFrequency words[MAX_SIZE];
    int size;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_words(argv[1], words, MAX_SIZE);
    count_words(argv[1], words, size);
    print_words(words, size);

    return 0;
}