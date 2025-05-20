//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: real-life
/* This program checks if a word is a palindrome or not */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

/* Function declaration */
int is_palindrome(char *word);

/* Main function */
int main()
{
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);
    if (is_palindrome(word))
    {
       printf("%s is a palindrome!\n", word);
    }
    else
    {
       printf("%s is not a palindrome.\n", word);
    }
    return 0;
}

/* Function definition */
int is_palindrome(char *word)
{
    /* Copy the word to temp variable and convert to lowercase */
    char temp[MAX_WORD_LENGTH];
    for (int i = 0; i < strlen(word); i++)
    {
        temp[i] = tolower(word[i]); 
    }
    
    /* Reverse the temp variable */
    int len = strlen(temp);
    for (int i = 0; i < len / 2; i++)
    {
        char tempChar = temp[i];
        temp[i] = temp[len - i - 1];
        temp[len - i - 1] = tempChar;
    }
    
    /* Compare the original word with the reversed temp variable */
    if (strcmp(word, temp) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}