//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
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
    for(int i = 0; str[i]; i++){
        str[i] = tolower((unsigned char)str[i]);
    }
}

int find_word(WordFrequency *words, int total, char *word) {
    for(int i = 0; i < total; i++) {
        if(strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void add_word(WordFrequency *words, int *total, char *word) {
    int index = find_word(words, *total, word);
    if(index == -1) {
        strncpy(words[*total].word, word, MAX_WORD_LENGTH);
        words[*total].count = 1;
        (*total)++;
    } else {
        words[index].count++;
    }
}

void print_frequencies(WordFrequency *words, int total) {
    printf("\nWord Frequencies:\n");
    printf("-----------------\n");
    for(int i = 0; i < total; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    WordFrequency words[MAX_WORDS];
    int total_words = 0;
    
    char word[MAX_WORD_LENGTH];
    while(fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        add_word(words, &total_words, word);
    }

    print_frequencies(words, total_words);
    fclose(file);
}

void clear_string_buffer(char *buffer, size_t size) {
    memset(buffer, 0, size);
}

int main() {
    printf("=== Word Frequency Counter ===\n");
    printf("Enter text filename to analyze: ");

    char filename[256];
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Strip newline

    process_file(filename);

    printf("Done processing the file!\n");
    return 0;
}