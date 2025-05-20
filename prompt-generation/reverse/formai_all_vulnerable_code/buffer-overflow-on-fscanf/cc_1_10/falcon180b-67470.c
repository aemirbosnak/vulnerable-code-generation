//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(char *filename, WordFrequency *word_frequency_table) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int word_length;
    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Word length exceeds maximum limit.\n");
            exit(1);
        }
        word[word_length - 1] = '\0'; // remove newline character
        for (int i = 0; i < word_length; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0'; // remove non-alphabetic characters
            }
        }
        int index = 0;
        while (index < MAX_NUM_WORDS && word_frequency_table[index].frequency!= 0) {
            index++;
        }
        if (index == MAX_NUM_WORDS) {
            printf("Maximum number of words exceeded.\n");
            exit(1);
        }
        strcpy(word_frequency_table[index].word, word);
        word_frequency_table[index].frequency++;
    }

    fclose(file);
}

void print_word_frequency(WordFrequency *word_frequency_table) {
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (word_frequency_table[i].frequency!= 0) {
            printf("%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
        }
    }
}

int main() {
    WordFrequency word_frequency_table[MAX_NUM_WORDS];
    char filename[MAX_WORD_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);
    read_file(filename, word_frequency_table);
    print_word_frequency(word_frequency_table);

    return 0;
}