//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }
}

void printWords(WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *input_fp = fopen(argv[1], "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE *output_fp = fopen(argv[2], "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    WordCount words[MAX_WORDS];
    readWords(input_fp, words);
    printWords(words);
    fclose(input_fp);
    fclose(output_fp);
    return 0;
}