//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_SIZE 50
#define DICTIONARY_SIZE 49999

char *dictionary[DICTIONARY_SIZE];

void add_word_to_dictionary(char *word)
{
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++)
        hash_value = (hash_value + tolower(word[i])) % DICTIONARY_SIZE;
    dictionary[hash_value] = word;
}

void load_dictionary(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: failed to open file %s\n", filename);
        exit(1);
    }

    char word[WORD_SIZE];
    while (fgets(word, WORD_SIZE, file))
    {
        word[strcspn(word, "\r\n")] = 0; // Remove newline character(s)
        add_word_to_dictionary(word);
    }

    fclose(file);
}

int is_dictionary_word(char *word)
{
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++)
        hash_value = (hash_value + tolower(word[i])) % DICTIONARY_SIZE;
    if (dictionary[hash_value])
    {
        if (strcmp(dictionary[hash_value], word) == 0)
            return 1;
    }
    return 0;
}

void check_word(char *word, int line_number)
{
    if (!is_dictionary_word(word))
        printf("Line %d: %s is misspelled\n", line_number, word);
}

void spell_check(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: failed to open file %s\n", filename);
        exit(1);
    }

    char word[WORD_SIZE];
    int line_number = 1;
    while (fgets(word, WORD_SIZE, file))
    {
        word[strcspn(word, "\r\n")] = 0; // Remove newline character(s)

        // Split line into words
        char *token = strtok(word, " ");
        while (token != NULL)
        {
            check_word(token, line_number);
            token = strtok(NULL, " ");
        }

        line_number++;
    }

    fclose(file);
}

int main()
{
    load_dictionary("dictionary.txt");
    spell_check("test.txt");

    return 0;
}