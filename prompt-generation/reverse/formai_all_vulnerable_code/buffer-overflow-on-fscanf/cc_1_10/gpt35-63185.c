//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_WORDS 5000

// Function to read words from a text file
void read_words(char words[][MAX_WORD_LENGTH], int *word_count, const char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Could not open file '%s'\n", file_name);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    int index = 0;
    while(fscanf(fp, "%s", word) != EOF) {
        strcpy(words[index], word);
        index++;
    }

    *word_count = index;

    fclose(fp);
}

// Function to check if a word is spelled correctly
bool is_spelled_correctly(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictionary_size)
{
    for(int i = 0; i < dictionary_size; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to print suggestions for a misspelled word
void print_suggestions(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictionary_size)
{
    printf("Did you mean:\n");
    for(int i = 0; i < dictionary_size; i++) {
        if(strncmp(word, dictionary[i], strlen(word)) == 0) {
            printf("- %s\n", dictionary[i]);
        }
    }
}

int main()
{
    char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
    int dictionary_size = 0;
    read_words(dictionary, &dictionary_size, "dictionary.txt");

    char input[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", input);

    // Convert input word to lowercase for easier comparison with dictionary words
    for(int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    if(is_spelled_correctly(input, dictionary, dictionary_size)) {
        printf("'%s' is spelled correctly!\n", input);
    } else {
        printf("'%s' is misspelled.\n", input);
        print_suggestions(input, dictionary, dictionary_size);
    }

    return 0;
}