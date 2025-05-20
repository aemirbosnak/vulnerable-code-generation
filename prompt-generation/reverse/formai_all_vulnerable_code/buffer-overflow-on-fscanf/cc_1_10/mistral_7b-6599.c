//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct {
    char word[20];
    int count;
} HashTableEntry;

int hash_func(char *str, int table_size) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += tolower(str[i]) * (i + 1);
    }
    hash %= table_size;
    return hash < 0 ? hash * -1 : hash;
}

void insert_word(HashTableEntry **table, char *word) {
    int hash = hash_func(word, TABLE_SIZE);
    if (!table[hash]) {
        table[hash] = (HashTableEntry *)calloc(1, sizeof(HashTableEntry));
        strcpy(table[hash]->word, word);
        table[hash]->count = 1;
    } else {
        table[hash]->count++;
    }
}

void print_table(HashTableEntry **table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        if (table[i]) {
            printf("Word: %s, Frequency: %d\n", table[i]->word, table[i]->count);
        }
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    HashTableEntry *hash_table[TABLE_SIZE] = {0};

    char word[20];
    int word_length;
    while (fscanf(file, " %s", word) != EOF) {
        word_length = strlen(word);
        if (word_length > 0 && isalpha(word[0])) {
            insert_word(hash_table, word);
        }
    }

    fclose(file);

    print_table(hash_table, TABLE_SIZE);

    return 0;
}