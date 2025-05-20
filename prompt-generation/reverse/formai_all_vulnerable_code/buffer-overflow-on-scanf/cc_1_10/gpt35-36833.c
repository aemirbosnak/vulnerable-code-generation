//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 100000

char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
int dictSize = 0;

int isValidWord(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isalpha(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

void readDictionaryFromFile(char *fileName)
{
    FILE *fp = fopen(fileName, "r");

    if (fp != NULL)
    {
        char line[MAX_WORD_LENGTH];
        while (fgets(line, sizeof(line), fp))
        {
            line[strcspn(line, "\r\n")] = 0;
            if (isValidWord(line))
            {
                strcpy(dictionary[dictSize], line);
                dictSize++;
            }
        }
        fclose(fp);
        printf("Dictionary loaded successfully with %d words.\n", dictSize);
    }
    else
    {
        printf("Error opening dictionary file.\n");
    }
}

int isWordInDictionary(char *word)
{
    for (int i = 0; i < dictSize; i++)
    {
        if (strcasecmp(dictionary[i], word) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void printSuggestedWords(char *word)
{
    printf("Suggested words for '%s':\n", word);

    // Generate suggested words with one substitution error
    for (int i = 0; i < strlen(word); i++)
    {
        char temp = word[i];
        for (int j = 0; j < 26; j++)
        {
            word[i] = 'a' + j;
            if (isWordInDictionary(word))
            {
                printf("%s\n", word);
            }
        }
        word[i] = temp;
    }

    // Generate suggested words with one deletion error
    for (int i = 0; i < strlen(word); i++)
    {
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, word);
        memmove(&temp[i], &temp[i + 1], strlen(temp) - i);
        if (isWordInDictionary(temp))
        {
            printf("%s\n", temp);
        }
    }

    // Generate suggested words with one insertion error
    for (int i = 0; i <= strlen(word); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char temp[MAX_WORD_LENGTH];
            strcpy(temp, "");
            strncpy(temp, word, i);
            temp[i] = 'a' + j;
            strcat(temp, word + i);
            if (isWordInDictionary(temp))
            {
                printf("%s\n", temp);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // Check for dictionary file argument
    if (argc < 2)
    {
        printf("Usage: %s <dictionary file>\n", argv[0]);
        return 0;
    }

    // Load dictionary from file
    readDictionaryFromFile(argv[1]);

    // Get word to spell check
    char word[MAX_WORD_LENGTH];
    printf("Enter word to spell check: ");
    scanf("%s", word);

    // Check if word is in dictionary
    if (isWordInDictionary(word))
    {
        printf("'%s' is spelled correctly.\n", word);
    }
    else
    {
        printf("'%s' is misspelled.\n", word);
        printSuggestedWords(word);
    }

    return 0;
}