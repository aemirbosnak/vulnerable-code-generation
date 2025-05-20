//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORDS];
    int frequency;
} WordFrequency;

void read_file(FILE* file, WordFrequency* word_frequency_table) {
    char word[MAX_WORDS];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(word_frequency_table[i].word, word);
        word_frequency_table[i].frequency = 1;
        i++;
    }
}

void count_words(char* text, WordFrequency* word_frequency_table) {
    char word[MAX_WORDS];
    int i = 0;
    char* token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in text.\n");
            exit(1);
        }
        strcpy(word_frequency_table[i].word, token);
        word_frequency_table[i].frequency = 1;
        i++;
        token = strtok(NULL, ",.?!;:");
    }
}

void print_word_frequency(WordFrequency* word_frequency_table) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_frequency_table[i].frequency > 0) {
            printf("%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        exit(1);
    }

    WordFrequency word_frequency_table[MAX_WORDS];
    read_file(file, word_frequency_table);
    fclose(file);

    char text[MAX_WORDS * 10];
    printf("Enter text to count word frequency:\n");
    fgets(text, sizeof(text), stdin);

    count_words(text, word_frequency_table);

    printf("\nWord frequency:\n");
    print_word_frequency(word_frequency_table);

    return 0;
}