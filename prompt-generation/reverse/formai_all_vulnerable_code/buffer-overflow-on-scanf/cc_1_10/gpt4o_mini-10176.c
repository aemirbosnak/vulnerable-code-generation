//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_word(char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i]) && str[i] != '\'') {
            return 0;
        }
    }
    return 1;
}

void add_word(WordFrequency *words, int *num_words, char *new_word) {
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*num_words].word, new_word);
    words[*num_words].count = 1;
    (*num_words)++;
}

void print_word_frequencies(WordFrequency *words, int num_words) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the file to read (e.g., input.txt): ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        if (is_valid_word(word)) {
            add_word(words, &num_words, word);
        }
    }

    fclose(file);
    
    print_word_frequencies(words, num_words);
    
    return EXIT_SUCCESS;
}