//FormAI DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    printf("\nOriginal string: %s\n", str);

    // Reversing the string
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("\nReversed string: %s\n", str);

    // Converting vowels to uppercase
    for (i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("\nString with vowels in uppercase: %s\n", str);

    // Counting number of consonants
    int vowels = 0, consonants = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowels++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            consonants++;
        }
    }

    printf("\nNumber of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    // Removing spaces from the string
    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
        }
    }

    printf("\nString with spaces removed: %s\n", str);

    // Calculating the sum of ASCII values
    int sum = 0;
    for (i = 0; i < len; i++)
    {
        sum += str[i];
    }

    printf("\nSum of ASCII values: %d", sum);

    return 0;
}