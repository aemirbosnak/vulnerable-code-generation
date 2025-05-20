//Falcon-180B DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency *words, int size, int *count) {
    char word[MAX_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*count >= size) {
            printf("Error: Exceeded maximum size of %d words.\n", size);
            exit(1);
        }
        for (int i = 0; i < *count; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                return;
            }
        }
        strcpy(words[*count].word, word);
        words[*count].frequency = 1;
        (*count)++;
    }
}

void writeWords(FILE *file, WordFrequency *words, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].frequency);
    }
}

void mergeWords(WordFrequency *left, int leftSize, WordFrequency *right, int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (strcmp(left[i].word, right[j].word) <= 0) {
            left[k++] = left[i++];
        } else {
            left[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        left[k++] = left[i++];
    }
    while (j < rightSize) {
        left[k++] = right[j++];
    }
}

void mergeSortWords(WordFrequency *words, int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    WordFrequency left[mid], right[size - mid];
    for (int i = 0; i < mid; i++) {
        strcpy(left[i].word, words[i].word);
        left[i].frequency = words[i].frequency;
    }
    for (int i = mid; i < size; i++) {
        strcpy(right[i - mid].word, words[i].word);
        right[i - mid].frequency = words[i].frequency;
    }
    mergeWords(left, mid, right, size - mid);
    for (int i = 0; i < size; i++) {
        words[i] = left[i];
    }
}

int main() {
    FILE *inputFile, *outputFile;
    WordFrequency words[MAX_SIZE];
    int count = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    readWords(inputFile, words, MAX_SIZE, &count);
    fclose(inputFile);

    mergeSortWords(words, count);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    writeWords(outputFile, words, count);
    fclose(outputFile);

    return 0;
}