//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    int word_length = strlen(word);

    // Check if the word is valid
    if (word_length < 1 || word_length > MAX_WORD_LENGTH)
    {
        printf("Error: Word length is invalid.\n");
        return 1;
    }

    // Check if the word contains vowels
    int has_vowel = 0;
    for (int i = 0; i < word_length; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            has_vowel = 1;
        }
    }

    // Check if the word contains consonants
    int has_consonant = 0;
    for (int i = 0; i < word_length; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            has_consonant = 1;
        }
    }

    // Check if the word is a palindrome
    int is_palindrome = 0;
    for (int i = 0; i < word_length; i++)
    {
        if (word[i] != word[word_length - 1 - i])
        {
            is_palindrome = 0;
        }
    }

    // Print the results
    printf("Word: %s\n", word);
    printf("Word length: %d\n", word_length);
    printf("Has vowels: %d\n", has_vowel);
    printf("Has consonants: %d\n", has_consonant);
    printf("Is palindrome: %d\n", is_palindrome);

    return 0;
}