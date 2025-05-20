//Gemma-7B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{
    char str[MAX];
    int i, len, word_count, char_count, vowel_count;
    float avg_word_length, avg_sentence_length;

    printf("Enter a text: ");
    gets(str);

    len = strlen(str);
    word_count = count_words(str);
    char_count = count_characters(str);
    vowel_count = count_vowels(str);

    avg_word_length = (float)char_count / word_count;
    avg_sentence_length = (float)len / word_count;

    printf("\nWord Count: %d", word_count);
    printf("\nCharacter Count: %d", char_count);
    printf("\nVowel Count: %d", vowel_count);
    printf("\nAverage Word Length: %.2f", avg_word_length);
    printf("\nAverage Sentence Length: %.2f", avg_sentence_length);

    return 0;
}

int count_words(char *str)
{
    int i, word_count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[i - 1] != ' ')
        {
            word_count++;
        }
    }

    return word_count;
}

int count_characters(char *str)
{
    int i, char_count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        char_count++;
    }

    return char_count;
}

int count_vowels(char *str)
{
    int i, vowel_count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            vowel_count++;
        }
    }

    return vowel_count;
}