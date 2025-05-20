//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} WordFrequencyTable;

void initialize_word_frequency_table(WordFrequencyTable *table) {
    table->word_counts = (WordCount *) malloc(MAX_WORDS * sizeof(WordCount));
    table->num_words = 0;
    memset(table->word_counts, 0, MAX_WORDS * sizeof(WordCount));
}

void free_word_frequency_table(WordFrequencyTable *table) {
    free(table->word_counts);
}

void add_word(WordFrequencyTable *table, char *word) {
    int i;
    for (i = 0; i < table->num_words; i++) {
        if (strcmp(table->word_counts[i].word, word) == 0) {
            table->word_counts[i].count++;
            return;
        }
    }
    if (table->num_words >= MAX_WORDS) {
        printf("Error: maximum number of words reached\n");
        return;
    }
    table->word_counts[table->num_words].word = strdup(word);
    table->word_counts[table->num_words].count = 1;
    table->num_words++;
}

void print_word_frequency_table(WordFrequencyTable *table, FILE *output) {
    int i;
    for (i = 0; i < table->num_words; i++) {
        fprintf(output, "%s: %d\n", table->word_counts[i].word, table->word_counts[i].count);
    }
}

void process_line(WordFrequencyTable *table, char *line) {
    char *word;
    char *token = strtok(line, ",.?!;:\"'");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            add_word(table, token);
        }
        token = strtok(NULL, ",.?!;:\"'");
    }
}

void process_file(WordFrequencyTable *table, FILE *input) {
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, input)!= NULL) {
        process_line(table, line);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: could not open output file\n");
        fclose(input);
        return 1;
    }
    WordFrequencyTable table;
    initialize_word_frequency_table(&table);
    process_file(&table, input);
    print_word_frequency_table(&table, output);
    fclose(input);
    fclose(output);
    free_word_frequency_table(&table);
    return 0;
}