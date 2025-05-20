//FormAI DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

int main()
{
    char text[MAX_WORDS][MAX_LENGTH];
    int i, j, k, n;

    /* Read text from stdin */
    printf("Enter text:\n");
    for(i = 0; i < MAX_WORDS; i++)
    {
        if(scanf("%s", text[i]) == EOF)
        {
            n = i;
            break;
        }
    }

    /* Check for misspelled words */
    char dictionary[] = "dictionary.txt";
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
    {
        printf("Error: Failed to open dictionary file.\n");
        return 1;
    }

    char word[MAX_LENGTH];
    while(fscanf(file, "%s", word) != EOF)
    {
        for(i = 0; i < n; i++)
        {
            if(strcmp(text[i], word) == 0)
            {
                break;
            }
            else if(i == n-1)
            {
                /* Word is not in dictionary, check for common misspellings */
                for(j = 0; j < strlen(word); j++)
                {
                    /* Replace each letter with a different letter */
                    char misspelling[MAX_LENGTH];
                    strcpy(misspelling, word);
                    for(k = 0; k < 26; k++)
                    {
                        if(k != tolower(word[j]) - 'a')
                        {
                            misspelling[j] = toupper(k + 'a');
                            if(strcmp(text[i], misspelling) == 0)
                            {
                                printf("Did you mean '%s'?\n", word);
                                break;
                            }
                            misspelling[j] = tolower(k + 'a');
                            if(strcmp(text[i], misspelling) == 0)
                            {
                                printf("Did you mean '%s'?\n", word);
                                break;
                            }
                        }
                    }
                    /* Remove each letter */
                    for(k = j; k < strlen(word); k++)
                    {
                        misspelling[k-1] = misspelling[k];
                        if(strcmp(text[i], misspelling) == 0)
                        {
                            printf("Did you mean '%s'?\n", word);
                            break;
                        }
                    }
                    /* Insert each letter */
                    for(k = strlen(word); k >= j; k--)
                    {
                        misspelling[k+1] = misspelling[k];
                        for(int l = 0; l < 26; l++)
                        {
                            misspelling[j] = toupper(l + 'a');
                            if(strcmp(text[i], misspelling) == 0)
                            {
                                printf("Did you mean '%s'?\n", word);
                                break;
                            }
                            misspelling[j] = tolower(l + 'a');
                            if(strcmp(text[i], misspelling) == 0)
                            {
                                printf("Did you mean '%s'?\n", word);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    fclose(file);

    return 0;
}