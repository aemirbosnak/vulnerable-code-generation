//FormAI DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000], c;
    int i, vowel_count = 0, consonant_count = 0, word_count = 0, char_count = 0;

    printf("Enter the text: ");

    //Get input from user
    while ((c = getchar()) != '\n')
    {
        if (char_count < 1000)
        {
            input[char_count] = c;
            char_count++;
        }
    }

    //Counting the number of words
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' && input[i - 1] != ' ')
        {
            word_count++;
        }
    }

    //If the last character is not a space, increment the last word count
    if (input[i - 1] != ' ')
    {
        word_count++;
    }

    printf("Number of words in the text: %d\n", word_count);

    //Counting the number of vowels and consonants
    for (i = 0; input[i] != '\0'; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
            {
                vowel_count++;
            }
            else
            {
                consonant_count++;
            }
        }
    }

    printf("Number of vowels in the text: %d\n", vowel_count);
    printf("Number of consonants in the text: %d\n", consonant_count);

    return 0;
}