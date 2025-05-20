//FormAI DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LENGTH 1000000  // maximum length of input file
#define MAX_WORD_LENGTH 50       // maximum length of a word
#define MAX_DICT_WORDS 100000    // maximum number of words in dictionary

char dict[MAX_DICT_WORDS][MAX_WORD_LENGTH];  // array to store dictionary words

// Function to load dictionary words from file
void load_dictionary(char* filename, int* num_words) {
    FILE* dict_file = fopen(filename, "r");

    if (dict_file == NULL) {
        printf("Error: Unable to open dictionary file for reading.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];

    // Read each word from file
    while (fscanf(dict_file, "%s", word) != EOF) {
        strncpy(dict[*num_words], word, MAX_WORD_LENGTH);
        (*num_words)++;
    }

    fclose(dict_file);
}

// Function to check if a word is in the dictionary
int is_word_in_dict(char* word, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dict[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check spelling for each word in input text file
void check_spelling(char* input_file, char* output_file, int num_words) {
    FILE* in_file = fopen(input_file, "r");
    FILE* out_file = fopen(output_file, "w");

    if (in_file == NULL || out_file == NULL) {
        printf("Error: Unable to open input/output files.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];

    // Read each word from file
    while(fscanf(in_file, "%s", word) != EOF) {
        // Remove any trailing punctuation
        int len = strlen(word);
        if (len > 1 && ispunct(word[len-1])) {
            word[len-1] = '\0';
        }
        // Check if word is in dictionary
        if (!is_word_in_dict(word, num_words)) {
            fprintf(out_file, "MISSPELLED: %s\n", word);
        }
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: spell_checker dictionary.txt input.txt output.txt\n");
        return 1;
    }

    char* dict_file = argv[1];
    char* input_file = argv[2];
    char* output_file = argv[3];

    int num_words = 0;

    // Load dictionary
    load_dictionary(dict_file, &num_words);

    // Check spelling of input file and write output to output file
    check_spelling(input_file, output_file, num_words);

    printf("Spelling check complete. Results written to output file.\n");

    return 0;
}