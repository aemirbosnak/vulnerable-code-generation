//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define the maximum length of a word in the dictionary
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in the dictionary
#define MAX_WORDS 1000

// Define the maximum length of an input sentence
#define MAX_SENTENCE_LENGTH 1000

// Define the struct for a dictionary entry
typedef struct dict_entry {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} dict_entry;

// Define the struct for the dictionary
typedef struct dictionary {
    dict_entry entries[MAX_WORDS];
    int num_entries;
} dictionary;

// Function to read a dictionary from a file
void read_dictionary(dictionary *dict, const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    dict->num_entries = 0;

    while (fscanf(fp, "%s %s", dict->entries[dict->num_entries].english, dict->entries[dict->num_entries].cat) == 2) {
        dict->num_entries++;
    }

    fclose(fp);
}

// Function to translate a sentence
void translate_sentence(dictionary *dict, const char *sentence) {
    char copy[MAX_SENTENCE_LENGTH];
    char *tok;

    strcpy(copy, sentence);

    tok = strtok(copy, " ");

    while (tok != NULL) {
        for (int i = 0; i < dict->num_entries; i++) {
            if (strcmp(tok, dict->entries[i].english) == 0) {
                printf("%s ", dict->entries[i].cat);
                break;
            }
        }

        tok = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    // Define the dictionary and read it from file
    dictionary dict;
    read_dictionary(&dict, "cat_dict.txt");

    // Get user input and translate sentence
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    translate_sentence(&dict, sentence);

    return 0;
}