//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000

struct WordFrequency {
    char word[100];
    int frequency;
};

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void readFile(FILE* file, struct WordFrequency* words) {
    char word[100];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        strcpy(words[i].word, word);
        words[i].frequency++;
    }
}

void writeFile(FILE* file, struct WordFrequency* words, int n) {
    qsort(words, n, sizeof(struct WordFrequency), compareWords);
    fprintf(file, "Word\tFrequency\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    struct WordFrequency words[MAX_WORDS];
    int n = 0;

    readFile(inputFile, words);

    writeFile(outputFile, words, n);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}