//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *word_frequencies;
    int num_words;
} WordFrequencyTable;

void init_word_frequency_table(WordFrequencyTable *table) {
    table->word_frequencies = malloc(MAX_WORDS * sizeof(WordFrequency));
    table->num_words = 0;
}

void add_word(WordFrequencyTable *table, char *word) {
    table->word_frequencies[table->num_words].word = strdup(word);
    table->word_frequencies[table->num_words].frequency = 1;
    table->num_words++;
}

void print_word_frequency_table(WordFrequencyTable *table) {
    for (int i = 0; i < table->num_words; i++) {
        printf("%s: %d\n", table->word_frequencies[i].word, table->word_frequencies[i].frequency);
    }
}

void free_word_frequency_table(WordFrequencyTable *table) {
    for (int i = 0; i < table->num_words; i++) {
        free(table->word_frequencies[i].word);
    }
    free(table->word_frequencies);
}

void read_file(char *filename, WordFrequencyTable *table) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int word_length;
    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > 0 && isalpha(word[0])) {
            add_word(table, word);
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    WordFrequencyTable table;
    init_word_frequency_table(&table);

    char filename[100];
    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    read_file(filename, &table);

    printf("Word frequency table:\n");
    print_word_frequency_table(&table);

    free_word_frequency_table(&table);

    return 0;
}