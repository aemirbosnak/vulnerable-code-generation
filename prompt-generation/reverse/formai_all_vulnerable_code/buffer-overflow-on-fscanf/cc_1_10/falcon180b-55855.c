//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_valid;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        dictionary[dictionary_size].word[0] = '\0';
        strcat(dictionary[dictionary_size].word, word);
        dictionary[dictionary_size++].is_valid = true;
    }

    fclose(file);
}

bool is_word_valid(char* word) {
    int length = strlen(word);
    if (length > MAX_WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }

    return true;
}

void spell_check(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file: %s\n", input_file);
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file: %s\n", output_file);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, input)!= NULL) {
        char* word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (!is_word_valid(word)) {
                fprintf(output, "Invalid word: %s\n", word);
            } else {
                bool is_valid = false;
                for (int i = 0; i < dictionary_size; i++) {
                    if (strcmp(dictionary[i].word, word) == 0) {
                        is_valid = true;
                        break;
                    }
                }

                if (!is_valid) {
                    fprintf(output, "Possible spelling mistake: %s\n", word);
                }
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    load_dictionary("dictionary.txt");
    spell_check(argv[1], argv[2]);

    return 0;
}