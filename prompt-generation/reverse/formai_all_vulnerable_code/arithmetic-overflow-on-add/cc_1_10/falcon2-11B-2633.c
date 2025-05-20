//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str)
{
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        if (tolower(str[i])!= tolower(str[j]))
            return 0;
    }
    return 1;
}

// Function to check if a word is a palindrome
int isWordPalindrome(char *word)
{
    int i, j;
    for (i = 0, j = strlen(word) - 1; i < j; i++, j--)
    {
        if (tolower(word[i])!= tolower(word[j]))
            return 0;
    }
    return 1;
}

// Function to spell check a word
int spellCheck(char *word)
{
    int i, j, k, count;
    int spell[26] = {0};
    for (i = 0; i < strlen(word); i++)
        spell[word[i] - 'a']++;

    for (i = 0; i < 26; i++)
        spell[i] += spell[i + 1];

    for (i = 0, count = 0; i < 26; i++)
        count += spell[i];

    for (i = 0; i < strlen(word); i++)
        if (tolower(word[i]) >= 'a' && tolower(word[i]) <= 'z')
            spell[word[i] - 'a']--;

    for (i = 0; i < strlen(word); i++)
    {
        if (tolower(word[i]) >= 'a' && tolower(word[i]) <= 'z')
            spell[word[i] - 'a']++;
        else if (tolower(word[i]) == '_')
            spell[word[i] - 'a']++;
    }

    for (i = 0; i < 26; i++)
        spell[i] += spell[i + 1];

    for (i = 0, count = 0; i < 26; i++)
        count += spell[i];

    if (isPalindrome(word))
        return 1;
    else if (isWordPalindrome(word))
        return 2;
    else
        return 0;
}

int main()
{
    char word[100];
    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);

    int status = spellCheck(word);
    if (status == 1)
        printf("%s is spelled correctly.\n", word);
    else if (status == 2)
        printf("%s is spelled as a palindrome.\n", word);
    else
        printf("%s is not spelled correctly.\n", word);

    return 0;
}