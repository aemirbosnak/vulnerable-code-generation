//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    char dictionary[1000][MAX_WORD_LENGTH];

    // Load the dictionary
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp)
    {
        char line[MAX_WORD_LENGTH];
        int i = 0;
        while (fgets(line, MAX_WORD_LENGTH, fp) != NULL)
        {
            dictionary[i][0] = line;
            i++;
        }
        fclose(fp);
    }

    // Get the word to check
    printf("Enter a word: ");
    scanf("%s", word);

    // Check if the word is in the dictionary
    int found = 0;
    for (int i = 0; dictionary[i][0] != NULL; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            found = 1;
            break;
        }
    }

    // Print the result
    if (found)
    {
        printf("The word %s is in the dictionary.\n", word);
    }
    else
    {
        printf("The word %s is not in the dictionary.\n", word);
    }

    return 0;
}