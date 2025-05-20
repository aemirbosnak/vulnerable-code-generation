//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

char **words = NULL;

void spell_check()
{
    char word[256];
    printf("Enter a word: ");
    scanf("%s", word);

    int i = 0;
    for (; words[i] && strcmp(word, words[i]) != 0; i++)
    {
        // Compare the word with all existing words
    }

    // If the word is not found, add it to the list
    if (words[i] == NULL)
    {
        words = realloc(words, (MAX_WORDS + 1) * sizeof(char *));
        words[i] = strdup(word);
    }
}

int main()
{
    // Allocate memory for the word list
    words = malloc(MAX_WORDS * sizeof(char *));

    // Initialize the word list
    words[0] = NULL;

    // Loop until the user enters "quit"
    while (1)
    {
        spell_check();

        char input[256];
        printf("Enter 'quit' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0)
        {
            break;
        }
    }

    // Free the memory allocated for the word list
    free(words);

    return 0;
}