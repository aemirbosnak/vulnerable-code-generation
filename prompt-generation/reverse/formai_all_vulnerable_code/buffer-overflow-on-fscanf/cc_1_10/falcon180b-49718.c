//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char input_buffer[MAX_WORD_LEN];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    int i;

    input_file = fopen("input_file.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", input_buffer)!= EOF) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(input_buffer, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            strcpy(word_counts[num_words].word, input_buffer);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    fclose(input_file);

    printf("Word Counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}