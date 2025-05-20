//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define NUM_WORDS 100000
#define HASH_TABLE_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *wordTable;
    int numWords;
} HashTable;

HashTable *createHashTable() {
    HashTable *table = (HashTable *) malloc(sizeof(HashTable));
    table->wordTable = (WordFrequency *) malloc(HASH_TABLE_SIZE * sizeof(WordFrequency));
    table->numWords = 0;
    return table;
}

int hash(char *word) {
    int hashValue = 0;
    for (int i = 0; i < strlen(word); i++) {
        hashValue += (int) word[i];
    }
    return hashValue % HASH_TABLE_SIZE;
}

void insertWord(HashTable *table, char *word) {
    int index = hash(word);
    WordFrequency *entry = &table->wordTable[index];
    while (entry->word[0]!= '\0' && strcmp(entry->word, word)!= 0) {
        entry++;
        if (entry == &table->wordTable[index + 1]) {
            entry->word[0] = '\0';
        }
    }
    entry->word[0] = '\0';
    entry->frequency++;
    table->numWords++;
}

void printHashTable(HashTable *table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordFrequency *entry = &table->wordTable[i];
        while (entry->word[0]!= '\0') {
            printf("%s: %d\n", entry->word, entry->frequency);
            entry++;
        }
    }
}

int main() {
    HashTable *table = createHashTable();
    char word[MAX_WORD_LENGTH];
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(file, "%s", word)!= EOF) {
        insertWord(table, word);
    }
    fclose(file);
    printf("Total number of words: %d\n", table->numWords);
    printf("Hash table:\n");
    printHashTable(table);
    return 0;
}