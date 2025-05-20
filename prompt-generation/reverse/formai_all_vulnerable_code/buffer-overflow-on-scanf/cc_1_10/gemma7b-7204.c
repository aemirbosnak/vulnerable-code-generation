//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spellcheck(char *word)
{
    char **dictionary = malloc(1000 * sizeof(char *));
    for (int i = 0; i < 1000; i++)
    {
        dictionary[i] = malloc(20 * sizeof(char));
    }

    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL)
    {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    int dictionary_size = 0;
    char line[200];
    while (fgets(line, 200, dict_file) != NULL)
    {
        dictionary[dictionary_size++] = strdup(line);
    }

    fclose(dict_file);

    int i = 0;
    for (; dictionary[i] != NULL; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            printf("Word found in dictionary: %s\n", word);
            break;
        }
    }

    if (dictionary[i] == NULL)
    {
        printf("Word not found in dictionary: %s\n", word);
    }

    for (int i = 0; i < 1000; i++)
    {
        free(dictionary[i]);
    }
    free(dictionary);
}

int main()
{
    char word[20];
    printf("Enter a word: ");
    scanf("%s", word);

    spellcheck(word);

    return 0;
}