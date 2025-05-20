//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

struct WordFrequency {
    char word[WORD_LENGTH];
    int frequency;
};

void readFile(FILE* file, struct WordFrequency* wordFrequencies);
void printWordFrequencies(struct WordFrequency* wordFrequencies, int numWords);

int main() {
    FILE* file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    struct WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    readFile(file, wordFrequencies);

    fclose(file);

    printf("\nWord frequencies:\n");
    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}

void readFile(FILE* file, struct WordFrequency* wordFrequencies) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORDS) {
                printf("Error: Too many words\n");
                exit(1);
            }

            wordFrequencies[i].word[0] = toupper(ch);
            wordFrequencies[i].frequency = 1;
            i++;
        } else if (isspace(ch)) {
            wordFrequencies[i-1].frequency++;
        }
    }
}

void printWordFrequencies(struct WordFrequency* wordFrequencies, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}