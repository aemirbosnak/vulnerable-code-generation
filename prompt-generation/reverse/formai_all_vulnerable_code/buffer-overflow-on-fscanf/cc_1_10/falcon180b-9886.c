//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequency_table, int table_size) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < table_size; i++) {
            if (strcmp(word_frequency_table[i].word, word) == 0) {
                word_frequency_table[i].frequency++;
                break;
            }
        }
        if (i == table_size) {
            strcpy(word_frequency_table[table_size].word, word);
            word_frequency_table[table_size].frequency = 1;
            table_size++;
        }
    }
}

void write_table(FILE *file, WordFrequency *word_frequency_table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        fprintf(file, "%s %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }
}

int main() {
    FILE *input_file, *output_file;
    WordFrequency word_frequency_table[100];
    int table_size = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    read_file(input_file, word_frequency_table, table_size);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    write_table(output_file, word_frequency_table, table_size);

    fclose(input_file);
    fclose(output_file);

    return 0;
}