//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 100
#define DICTIONARY_SIZE 1000
#define MAX_FILE_SIZE 1000000

// Function to read dictionary file and store it in a hash table
void read_dictionary(char *filename, char **dictionary) {
    FILE *file;
    char word[WORD_LENGTH];
    int index = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file!\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        dictionary[index++] = strdup(word);
    }

    fclose(file);
}

// Function to check if a word is in the dictionary
int is_in_dictionary(char **dictionary, char *word) {
    int length = strlen(word);
    int i = 0;
    while (dictionary[i]!= NULL) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to read input file and check for spelling errors
void spell_check(char *filename, char **dictionary) {
    FILE *file;
    char line[MAX_FILE_SIZE];
    char word[WORD_LENGTH];
    int index = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open input file!\n");
        exit(1);
    }

    while (fgets(line, MAX_FILE_SIZE, file)!= NULL) {
        char *token = strtok(line, " \t\r\n\f\v");
        while (token!= NULL) {
            if (strlen(token) > WORD_LENGTH - 1) {
                printf("Error: Word too long! (%s)\n", token);
                exit(1);
            }
            strcpy(word, token);
            if (!is_in_dictionary(dictionary, word)) {
                printf("Possible spelling error: %s\n", word);
            }
            token = strtok(NULL, " \t\r\n\f\v");
        }
        index = 0;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <input_file>\n", argv[0]);
        exit(1);
    }

    char **dictionary = NULL;
    read_dictionary(argv[1], &dictionary);
    spell_check(argv[2], dictionary);

    return 0;
}