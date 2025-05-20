//FormAI DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_DICTIONARY_SIZE 2000

char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];

int loadDictionary(const char *filename);
int spellCheck(char *word);

int main()
{
    int dictSize;
    char word[MAX_WORD_LENGTH];
    
    dictSize = loadDictionary("dictionary.txt");
    
    printf("Spell Checker\n");
    printf("Enter words in lower case. Type q to quit.\n");
    
    do
    {
        printf("spell> ");
        scanf("%s", word);

        if(strcmp(word, "q") == 0)
            break;
            
        if(spellCheck(word))
            printf("%s is spelled correctly.\n", word);
        else
            printf("%s is misspelled.\n", word);
            
    } while(1);
    
    return 0;
}

int loadDictionary(const char *filename)
{
    FILE *f;
    int i = 0;
    
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Error: Unable to open dictionary file %s\n", filename);
        return 0;
    }
    
    while(fscanf(f, "%s", dictionary[i]) != EOF && i < MAX_DICTIONARY_SIZE)
    {
        for(int j = 0; j < strlen(dictionary[i]); j++)
        {
            dictionary[i][j] = tolower(dictionary[i][j]);
        }
        
        i++;
    }
    
    fclose(f);
    
    return i;
}

int spellCheck(char *word)
{
    int found = 0;
    int i;
    
    for(i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
    
    for(i = 0; i < MAX_DICTIONARY_SIZE; i++)
    {
        if(strcmp(dictionary[i], word) == 0)
        {
            found = 1;
            break;
        }
    }
    
    return found;
}