//FormAI DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int length, i, j, vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    length = strlen(str);

    // Removing trailing newline character from string
    if (str[length - 1] == '\n')
    {
        str[length - 1] = '\0';
        length--;
    }

    // Reversing the string
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    puts("The reversed string is:");
    puts(str);

    // Counting the number of vowels and consonants
    for (i = 0; i < length; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    printf("Number of vowels in the string: %d\n", vowels);
    printf("Number of consonants in the string: %d\n", consonants);

    // Converting the first letter of each word to uppercase
    for (i = 0; i < length; i++)
    {
        if (i == 0 && str[i] != ' ' || str[i] != ' ' && str[i - 1] == ' ')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }

    puts("The string with first letter of each word in uppercase is:");
    puts(str);

    return 0;
}