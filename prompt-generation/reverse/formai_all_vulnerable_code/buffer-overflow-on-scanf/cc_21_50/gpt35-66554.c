//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], temp;
    int i, j, k;

    printf("Enter a string: ");
    scanf("%s", str);

    // Reversing the string
    j = strlen(str) - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("Reversed String: %s\n", str);

    // Counting the number of vowels in the string
    int vowels = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowels++;
        }
    }
    printf("Number of vowels in the string: %d\n", vowels);

    // Removing all occurrences of a character from the string
    char ch;
    printf("Enter a character you want to remove from the string: ");
    scanf(" %c", &ch);
    k = 0;
    for (i = j = 0; i < strlen(str); i++)
    {
        if (str[i] != ch)
        {
            str[j++] = str[i];
        }
        else
        {
            k++;
        }
    }
    str[j] = '\0';
    printf("New string after removing all occurrences of the character '%c': %s\n", ch, str);

    // Converting the string to title case
    for (i = 0; str[i] != '\0'; i++)
    {
        if (i == 0 || str[i - 1] == ' ')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
        else
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
        }
    }
    printf("String in title case: %s\n", str);

    return 0;
}