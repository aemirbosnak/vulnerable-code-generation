//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define HASH_SIZE 1009

typedef struct WordEntry {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordEntry *next;
} WordEntry;

WordEntry *hash_table[HASH_SIZE];

unsigned int hash(const char *word) {
    unsigned long int hash_value = 0;
    while (*word) {
        hash_value = (hash_value << 5) + *word++;
    }
    return hash_value % HASH_SIZE;
}

void insert_word(const char *word) {
    unsigned int index = hash(word);
    WordEntry *entry = hash_table[index];

    while (entry) {
        if (strcmp(entry->word, word) == 0) {
            entry->count++;
            return;
        }
        entry = entry->next;
    }

    WordEntry *new_entry = (WordEntry *)malloc(sizeof(WordEntry));
    strncpy(new_entry->word, word, MAX_WORD_LENGTH);
    new_entry->count = 1;
    new_entry->next = hash_table[index];
    hash_table[index] = new_entry;
}

void print_word_frequency() {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        WordEntry *entry = hash_table[i];
        while (entry) {
            printf("%s: %d\n", entry->word, entry->count);
            entry = entry->next;
        }
    }
}

void free_memory() {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordEntry *entry = hash_table[i];
        while (entry) {
            WordEntry *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Normalize the word to lower case and strip punctuation
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
            if (!isalnum(word[i]) && word[i] != '-') {
                word[i] = '\0'; // Null terminate at the first non-alphanumeric character
                break;
            }
        }
        if (strlen(word) > 0) {
            insert_word(word);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(hash_table, 0, sizeof(hash_table));

    process_file(argv[1]);
    print_word_frequency();
    free_memory();

    return 0;
}