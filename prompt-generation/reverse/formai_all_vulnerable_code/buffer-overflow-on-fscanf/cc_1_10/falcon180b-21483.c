//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *input_file;
    char input_string[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", input_string)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
        words[num_words].word[0] = toupper(input_string[0]);
        strcpy(&words[num_words].word[1], &input_string[1]);
        words[num_words].count = 1;
        num_words++;
    }

    fclose(input_file);

    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    printf("Word\tCount\n");
    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}