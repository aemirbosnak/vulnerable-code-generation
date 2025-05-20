//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TABLE_SIZE 101
#define WORD_LEN_MAX 50

typedef struct {
    char word[WORD_LEN_MAX];
    int count;
} HashTableEntry;

unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void str_toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

bool is_delimiter(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == ';' || c == ':' || c == '!' || c == '?' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
}

bool is_word_separator(char c, char prev) {
    return is_delimiter(c) && !is_delimiter(prev);
}

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    HashTableEntry *table = calloc(TABLE_SIZE, sizeof(HashTableEntry));

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");

    if (!input_file || !output_file) {
        perror("Error opening file");
        free(table);
        exit(EXIT_FAILURE);
    }

    char current_word[WORD_LEN_MAX];
    int current_word_length = 0;
    int hash_index;
    char prev = ' ';

    while (fscanf(input_file, " %s", current_word) != EOF) {
        str_toLowerCase(current_word);

        hash_index = hash(current_word);

        if (table[hash_index].count > 0) {
            table[hash_index].count += strlen(current_word);
        } else {
            strcpy(table[hash_index].word, current_word);
            table[hash_index].count = strlen(current_word);
        }

        current_word_length = 0;
        prev = current_word[strlen(current_word) - 1];
    }

    fprintf(output_file, "Word counts:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].count > 0) {
            fprintf(output_file, "%s: %d\n", table[i].word, table[i].count);
        }
    }

    fclose(input_file);
    fclose(output_file);

    free(table);

    return EXIT_SUCCESS;
}