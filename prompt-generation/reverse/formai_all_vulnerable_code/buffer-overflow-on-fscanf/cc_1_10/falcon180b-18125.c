//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int words_count = 0;
Word dictionary[MAX_WORDS];

void add_word(char* word) {
    int i;
    for (i = 0; i < words_count; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            dictionary[i].count++;
            return;
        }
    }
    strcpy(dictionary[words_count].word, word);
    dictionary[words_count].count = 1;
    words_count++;
}

void load_dictionary(char* file_name) {
    FILE* file = fopen(file_name, "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        add_word(word);
    }
    fclose(file);
}

int is_word_correct(char* word) {
    int i;
    for (i = 0; i < words_count; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void print_misspelled_words(FILE* output_file, char* input_file_contents) {
    char* token = strtok(input_file_contents, ",.?!;:");
    while (token!= NULL) {
        if (!is_word_correct(token)) {
            fprintf(output_file, "%s\n", token);
        }
        token = strtok(NULL, ",.?!;:");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    load_dictionary("dictionary.txt");
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    char input_file_contents[1000000];
    fread(input_file_contents, 1, sizeof(input_file_contents), input_file);
    fclose(input_file);
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    print_misspelled_words(output_file, input_file_contents);
    fclose(output_file);
    return 0;
}