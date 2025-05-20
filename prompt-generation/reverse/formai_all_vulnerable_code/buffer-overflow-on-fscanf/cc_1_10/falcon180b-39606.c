//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void create_word_frequency_table(char *filename, WordFrequency *table, int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_SIZE];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= size) {
            printf("Table is full. Cannot add more words.\n");
            break;
        }

        table[i].word = strdup(word);
        table[i].frequency = 1;
        i++;
    }

    fclose(file);
}

void print_word_frequency_table(WordFrequency *table, int size) {
    for (int i = 0; i < size; i++) {
        if (table[i].word!= NULL) {
            printf("%s: %d\n", table[i].word, table[i].frequency);
        }
    }
}

void search_word_frequency_table(WordFrequency *table, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (table[i].word!= NULL && strcmp(table[i].word, word) == 0) {
            printf("%s: %d\n", word, table[i].frequency);
            return;
        }
    }

    printf("%s not found in table.\n", word);
}

int main() {
    char filename[MAX_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency table[MAX_SIZE];
    int size = 0;

    create_word_frequency_table(filename, table, MAX_SIZE);
    print_word_frequency_table(table, size);

    char search_word[MAX_SIZE];
    while (1) {
        printf("\nEnter word to search (or type 'exit' to quit): ");
        scanf("%s", search_word);

        if (strcmp(search_word, "exit") == 0) {
            break;
        }

        search_word_frequency_table(table, size, search_word);
    }

    return 0;
}