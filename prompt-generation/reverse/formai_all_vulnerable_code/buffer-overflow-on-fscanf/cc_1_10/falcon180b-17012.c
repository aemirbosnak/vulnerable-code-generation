//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequency_table) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    int i;

    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
            for (i = 0; i < word_length; i++) {
                word[i] = tolower(word[i]);
            }
            word_frequency_table[word_hash(word)].frequency++;
        }
    }
}

int word_hash(char *word) {
    int hash = 0;
    int i;

    for (i = 0; i < strlen(word); i++) {
        hash = (hash * 31) ^ tolower(word[i]);
    }

    return hash % MAX_WORDS;
}

void print_word_frequency_table(WordFrequency *word_frequency_table) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (word_frequency_table[i].frequency > 0) {
            printf("%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    WordFrequency word_frequency_table[MAX_WORDS];

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    read_file(file, word_frequency_table);

    fclose(file);

    print_word_frequency_table(word_frequency_table);

    return 0;
}