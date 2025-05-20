//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Author: Ken Thompson
// Program: Spell checker in C

// Global variables
int num_words = 0;
char dictionary[100][50];

// Function to count number of words in a file
int count_words(FILE *file) {
    int count = 0;
    char word[50];
    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }
    rewind(file); // Reset file pointer to beginning
    return count;
}

// Function to load dictionary file into memory
void load_dictionary(FILE *file) {
    char word[50];
    while (fscanf(file, "%s", word) != EOF) {
        strcpy(dictionary[num_words], word);
        num_words++;
    }
    fclose(file); // Close dictionary file
}

// Function to check if a word is in the dictionary
bool check_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to convert word to lowercase
void tolowercase(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a character is alphabetic
bool isalphabetic(char c) {
    return isalpha(c) != 0;
}

// Function to spell-check a file
void spell_check(FILE *file) {
    char word[50];
    int line_num = 1;
    while (fgets(word, 50, file) != NULL) {
        char *token = strtok(word, " \n");
        while (token != NULL) {
            tolowercase(token);
            if (!check_word(token)) {
                printf("Error on line %d: %s\n", line_num, token);
            }
            token = strtok(NULL, " \n");
        }
        line_num++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./spellchecker <dictionary_file> <input_file>\n");
        return 1;
    }
    FILE *dictionary_file = fopen(argv[1], "r");
    if (dictionary_file == NULL) {
        printf("Error: could not open dictionary file\n");
        return 1;
    }
    FILE *input_file = fopen(argv[2], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    num_words = count_words(dictionary_file);
    load_dictionary(dictionary_file);
    spell_check(input_file);
    fclose(input_file); // Close input file
    return 0;
}