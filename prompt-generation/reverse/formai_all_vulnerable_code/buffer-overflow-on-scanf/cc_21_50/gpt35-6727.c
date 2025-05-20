//FormAI DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int i, j = 0;

    printf("Enter a string:\n");
    scanf("%s", string);

    printf("\nOriginal string: %s\n", string);

    // Reverse the string
    for (i = strlen(string) - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
        j++;
        if (j % 5 == 0)
            printf(" ");
    }

    printf("\nThe reversed string is: ");
    for (i = strlen(string) - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
        if (i % 3 == 0)
            printf(" ");
    }
    printf("\n");

    // Count the number of vowels and consonants in the string
    int vowels = 0, consonants = 0;
    for(i = 0; i < strlen(string); i++)
    {
        if (string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U' ||
            string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            vowels++;
        else if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
            consonants++;
    }
    printf("There are %d vowels and %d consonants in the string\n", vowels, consonants);

    // Replace all occurances of 'e' with '3'
    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == 'e')
            string[i] = '3';
    }
    printf("The new string is: %s\n", string);

    // Find the length of the longest word in the string
    int max_count = 0, count = 0;
    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] != ' ')
            count++;
        else
        {
            if (count > max_count)
                max_count = count;
            count = 0;
        }
    }
    if (count > max_count)
        max_count = count;

    printf("The length of the longest word in the string is %d\n", max_count);

    return 0;
}