//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
    char string1[100], string2[100];

    // Taking input strings from user
    printf("Enter a string: ");
    scanf("%s", string1);

    printf("Enter another string: ");
    scanf("%s", string2);

    // Finding length of the strings
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    // Concatenating the two strings
    strcat(string1, string2);

    printf("Strings concatenated: %s\n", string1);

    // Reversing the concatenated string
    int i, j = 0;
    char temp;
    for (i = 0, j = len1 + len2 - 1; i < j; i++, j--)
    {
        temp = string1[i];
        string1[i] = string1[j];
        string1[j] = temp;
    }

    printf("Strings reversed: %s\n", string1);

    // Converting the reversed string to all lowercase
    for (i = 0; string1[i] != '\0'; i++)
    {
        if (string1[i] >= 'A' && string1[i] <= 'Z')
        {
            string1[i] = string1[i] + 32;
        }
    }

    printf("Lowercase string: %s\n", string1);

    // Finding the first occurrence of a character in the string
    char c;
    printf("Enter a character to find its first occurrence: ");
    scanf(" %c", &c);

    int pos = -1;
    for (i = 0; string1[i] != '\0'; i++)
    {
        if (string1[i] == c)
        {
            pos = i;
            break;
        }
    }

    if (pos >= 0)
    {
        printf("The first occurrence of '%c' is at position %d\n", c, pos + 1);
    }
    else
    {
        printf("'%c' does not occur in the string.\n", c);
    }

    return 0;
}