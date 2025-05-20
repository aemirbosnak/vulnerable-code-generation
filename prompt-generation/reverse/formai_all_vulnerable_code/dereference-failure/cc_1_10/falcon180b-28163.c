//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 31
#define HASH_TABLE_SIZE 1009

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

typedef struct {
    WordFrequency *table;
    int size;
} HashTable;

void initHashTable(HashTable *table) {
    table->table = (WordFrequency *) malloc(HASH_TABLE_SIZE * sizeof(WordFrequency));
    table->size = HASH_TABLE_SIZE;
    for (int i = 0; i < table->size; i++) {
        table->table[i].word[0] = '\0';
        table->table[i].count = 0;
    }
}

int hash(char *word) {
    int hashValue = 0;
    while (*word) {
        hashValue = (hashValue * 31) ^ tolower(*word++);
    }
    return hashValue % HASH_TABLE_SIZE;
}

void insertWord(HashTable *table, char *word) {
    int index = hash(word);
    while (table->table[index].word[0]!= '\0') {
        if (strcmp(table->table[index].word, word) == 0) {
            table->table[index].count++;
            return;
        }
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    strcpy(table->table[index].word, word);
    table->table[index].count = 1;
}

void printHashTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->table[i].word[0]!= '\0') {
            printf("%s: %d\n", table->table[i].word, table->table[i].count);
        }
    }
}

int isPalindrome(char *word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i])!= tolower(word[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_WORD_LENGTH];
    HashTable table;
    initHashTable(&table);

    while (fscanf(stdin, "%s", input)!= EOF) {
        if (isPalindrome(input)) {
            insertWord(&table, input);
        }
    }

    printHashTable(&table);

    return 0;
}