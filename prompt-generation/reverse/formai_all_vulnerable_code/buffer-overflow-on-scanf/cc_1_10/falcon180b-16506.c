//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(FILE *file, Word *words) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void spell_check(FILE *file, Word *words) {
    char word[MAX_WORD_LENGTH];
    int i;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Misspelled word: %s\n", word);
        }
    }
}

void print_results(Word *words) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("Word: %s\n", words[i].word);
            printf("Count: %d\n\n", words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    Word words[MAX_WORDS];
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_WORD_LENGTH];
    char output_filename[MAX_WORD_LENGTH];

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    read_file(input_file, words);

    fclose(input_file);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    spell_check(input_file, words);

    fclose(input_file);
    fclose(output_file);

    print_results(words);

    return 0;
}