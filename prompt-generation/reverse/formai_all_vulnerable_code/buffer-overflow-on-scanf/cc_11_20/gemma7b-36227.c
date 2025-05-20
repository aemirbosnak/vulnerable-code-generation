//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a message: ");
    scanf("%s", str);

    // Analyze the message
    int length = strlen(str);
    printf("Message length: %d", length);

    // Check for vowels
    int vowel_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            vowel_count++;
        }
    }

    // Check for consonants
    int consonant_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            consonant_count++;
        }
    }

    // Check for numbers
    int number_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            number_count++;
        }
    }

    // Check for punctuation marks
    int punctuation_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= '!' && str[i] <= '/')
        {
            punctuation_count++;
        }
    }

    // Print the results
    printf("\nVowel count: %d", vowel_count);
    printf("\nConsonant count: %d", consonant_count);
    printf("\nNumber count: %d", number_count);
    printf("\nPunctuation count: %d", punctuation_count);

    return 0;
}