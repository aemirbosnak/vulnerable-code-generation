//Falcon-180B DATASET v1.0 Category: Text processing ; Style: modular
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
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= table_size) {
            printf("Error: Table is full.\n");
            exit(1);
        }

        strcpy(word_frequency_table[i].word, word);
        word_frequency_table[i].frequency = 1;
        i++;
    }
}

void print_table(WordFrequency *word_frequency_table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        if (word_frequency_table[i].frequency > 0) {
            printf("%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    int table_size;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    printf("Enter table size: ");
    scanf("%d", &table_size);

    WordFrequency *word_frequency_table = (WordFrequency *) malloc(table_size * sizeof(WordFrequency));

    if (word_frequency_table == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    read_file(file, word_frequency_table, table_size);

    print_table(word_frequency_table, table_size);

    free(word_frequency_table);

    return 0;
}