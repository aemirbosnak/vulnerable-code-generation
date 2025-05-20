//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    FILE *input_fp, *output_fp;
    char line[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output_fp, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}