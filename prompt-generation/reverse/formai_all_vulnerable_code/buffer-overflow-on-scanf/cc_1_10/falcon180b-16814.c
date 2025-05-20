//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_LINE_LENGTH 10000

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int num_words;
} WordFrequencyTable;

void initialize_word_frequency_table(WordFrequencyTable *table) {
    table->num_words = 0;
    table->words = NULL;
}

void add_word(WordFrequencyTable *table, char *word) {
    WordFrequency *new_word = malloc(sizeof(WordFrequency));
    new_word->word = strdup(word);
    new_word->frequency = 1;

    table->words = realloc(table->words, sizeof(WordFrequency) * ++table->num_words);
    table->words[table->num_words - 1] = *new_word;
}

void print_word_frequency_table(WordFrequencyTable *table) {
    for (int i = 0; i < table->num_words; i++) {
        printf("%s: %d\n", table->words[i].word, table->words[i].frequency);
    }
}

void free_word_frequency_table(WordFrequencyTable *table) {
    for (int i = 0; i < table->num_words; i++) {
        free(table->words[i].word);
    }
    free(table->words);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordFrequencyTable table;
    initialize_word_frequency_table(&table);

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_length = strlen(line);
        char *word_start = line;
        while (isspace(*word_start)) {
            word_start++;
        }
        char *word_end = word_start;
        while (!isspace(*word_end) && word_end - word_start < MAX_WORD_LENGTH) {
            word_end++;
        }
        if (word_end - word_start > 0) {
            add_word(&table, strndup(word_start, word_end - word_start));
        }
    }

    fclose(file);

    print_word_frequency_table(&table);

    free_word_frequency_table(&table);

    return 0;
}