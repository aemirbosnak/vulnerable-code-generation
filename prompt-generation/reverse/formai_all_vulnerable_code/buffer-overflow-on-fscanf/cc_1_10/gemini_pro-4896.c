//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 256

// Function to load the dictionary into memory
int load_dictionary(char *filename, char ***dictionary)
{
    FILE *fp;
    int num_words;
    char **words;

    // Open the dictionary file
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening dictionary file %s\n", filename);
        return -1;
    }

    // Get the number of words in the dictionary
    fscanf(fp, "%d\n", &num_words);

    // Allocate memory for the words
    words = malloc(sizeof(char *) * num_words);
    if (words == NULL)
    {
        fprintf(stderr, "Error allocating memory for words\n");
        return -1;
    }

    // Read the words from the dictionary file
    for (int i = 0; i < num_words; i++)
    {
        char word[MAX_WORD_LENGTH];
        fscanf(fp, "%s\n", word);

        // Allocate memory for the word
        words[i] = malloc(sizeof(char) * (strlen(word) + 1));
        if (words[i] == NULL)
        {
            fprintf(stderr, "Error allocating memory for word %d\n", i);
            return -1;
        }

        // Copy the word into the array
        strcpy(words[i], word);
    }

    // Close the dictionary file
    fclose(fp);

    *dictionary = words;
    return num_words;
}

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word, char **dictionary, int num_words)
{
    for (int i = 0; i < num_words; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Function to check the spelling of a word
int check_spelling(char *word, char **dictionary, int num_words)
{
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the dictionary
    if (is_in_dictionary(word, dictionary, num_words))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Print the word to the screen with color and bold effects if is misspelled
void print_word(char *word, int is_misspelled)
{
    if (is_misspelled)
    {
        printf("\033[1;31m%s\033[0m\n", word);
    }
    else
    {
        printf("%s\n", word);
    }
}

// Function to check the spelling of a sentence or paragraph
int check_spelling_text(char *text, char **dictionary, int num_words)
{
    int num_misspelled = 0;
    char *word;

    // Tokenize the text into words
    word = strtok(text, " \t\n\r");
    while (word != NULL)
    {
        // Check the spelling of the word
        if (!check_spelling(word, dictionary, num_words))
        {
            num_misspelled++;
            print_word(word, 1);
        }
        else
        {
            print_word(word, 0);
        }

        // Get the next word
        word = strtok(NULL, " \t\n\r");
    }

    return num_misspelled;
}

int main(int argc, char **argv)
{
    int num_words;
    char **dictionary;
    char text[1024];
    int num_misspelled;

    // Load the dictionary into memory
    num_words = load_dictionary("dictionary.txt", &dictionary);
    if (num_words < 0)
    {
        return -1;
    }

    // Get the text to check
    printf("Enter text to check (max 1024 characters): ");
    fgets(text, 1024, stdin);

    // Check the spelling of the text
    num_misspelled = check_spelling_text(text, dictionary, num_words);

    // Print the results
    printf("\nNumber of misspelled words: %d\n", num_misspelled);

    return 0;
}