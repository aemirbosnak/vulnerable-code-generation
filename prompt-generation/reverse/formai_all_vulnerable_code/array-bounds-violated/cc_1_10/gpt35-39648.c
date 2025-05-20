//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_valid_char(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return 1;
    }
    else if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_valid_word(char *word)
{
    int i;
    int len = strlen(word);
    
    for (i = 0; i < len; i++)
    {
        if (!is_valid_char(word[i]))
        {
            return 0;
        }
    }
    
    return 1;
}

void check_word(char *word)
{
    if (is_valid_word(word))
    {
        printf("\nWord \"%s\" is already spelled correctly.\n", word);
    }
    else
    {
        printf("\nWord \"%s\" is spelled incorrectly.\n", word);
    }
}

int main()
{
    char input[100];
    char *word;
    int i, j, len;
    
    printf("Enter the sentence: ");
    fgets(input, 100, stdin);
    
    len = strlen(input);
    input[len - 1] = '\0';
    
    word = strtok(input, " ,.-\n\r");
    
    while (word != NULL)
    {
        check_word(word);
        
        word = strtok(NULL, " ,.-\n\r");
    }
    
    return 0;
}