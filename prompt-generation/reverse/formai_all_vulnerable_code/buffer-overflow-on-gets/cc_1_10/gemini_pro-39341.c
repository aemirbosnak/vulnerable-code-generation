//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Retro-style word count tool

// Defines
#define MAX_WORDS 100
#define MAX_WORD_LEN 20

// Function prototypes
int count_words(char *str);
void print_words(char **words, int num_words);

// Main function
int main()
{
    // Welcome message
    printf("*****************************************\n");
    printf("** Welcome to the Retro Word Count Tool **\n");
    printf("*****************************************\n\n");

    // Get input from user
    char str[256];
    printf("Enter a string: ");
    gets(str);

    // Count the number of words
    int num_words = count_words(str);

    // Create an array of strings to store the words
    char **words = (char **)malloc(sizeof(char *) * num_words);

    // Extract the words from the string
    int i = 0;
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        words[i] = (char *)malloc(sizeof(char) * (strlen(word) + 1));
        strcpy(words[i], word);
        i++;

        word = strtok(NULL, " ");
    }

    // Print the words
    printf("\nWords:\n");
    print_words(words, num_words);

    // Free the memory allocated for the words
    for (i = 0; i < num_words; i++)
    {
        free(words[i]);
    }
    free(words);

    // Goodbye message
    printf("\n*****************************************\n");
    printf("**          Thank you for using         **\n");
    printf("** The Retro Word Count Tool!           **\n");
    printf("*****************************************\n\n");

    return 0;
}

// Function to count the number of words in a string
int count_words(char *str)
{
    int num_words = 0;
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        num_words++;
        word = strtok(NULL, " ");
    }

    return num_words;
}

// Function to print an array of words
void print_words(char **words, int num_words)
{
    for (int i = 0; i < num_words; i++)
    {
        printf("%s\n", words[i]);
    }
}