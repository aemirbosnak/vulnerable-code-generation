//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

// Word frequency table
int word_frequency[MAX_WORDS];

// Spell checking function
int spell_check(char* word) {
    int i;

    // Check if word is in frequency table
    for(i = 0; i < MAX_WORDS; i++) {
        if(strcmp(word, word_frequency[i]) == 0) {
            return 1;
        }
    }

    // Word not found in frequency table
    return 0;
}

// Load word frequency table from file
void load_word_frequency_table(char* filename) {
    FILE* fp;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: could not open word frequency table file.\n");
        exit(1);
    }

    while(fscanf(fp, "%s", word)!= EOF) {
        word_frequency[i] = strdup(word);
        i++;
    }

    fclose(fp);
}

// Main program
int main(int argc, char* argv[]) {
    char word[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    char input_file[MAX_WORD_LENGTH];
    FILE* input_fp;
    FILE* output_fp;
    int i;

    // Load word frequency table
    load_word_frequency_table("word_frequency.txt");

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open input file
    input_fp = fopen(input_file, "r");
    if(input_fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Open output file
    sprintf(filename, "%s.spell_checked", input_file);
    output_fp = fopen(filename, "w");
    if(output_fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Spell check each word in input file
    while(fscanf(input_fp, "%s", word)!= EOF) {
        if(spell_check(word)) {
            // Word is spelled correctly
            fprintf(output_fp, "%s\n", word);
        } else {
            // Word is not spelled correctly
            printf("Possible spelling error: %s\n", word);
        }
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}