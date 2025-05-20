//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    char input_file[100];
    char output_file[100];
    FILE *input_fp, *output_fp;
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Please enter the name of the output file: ");
    scanf("%s", output_file);

    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while (fscanf(input_fp, "%s", word)!= EOF) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output_fp, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}