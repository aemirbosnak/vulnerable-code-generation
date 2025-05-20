//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);

    // Converting the string to uppercase
    printf("\nOriginal String: %s\n", str);
    strcat(str, " ");
    strcat(str, "Modified String: ");
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    printf("%s\n", str);

    // Reverse the string
    printf("\nReversed String: ");
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    // Counting the number of vowels
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
    }
    printf("\nNumber of vowels: %d\n", count);

    // Removing all whitespaces
    char str1[1000];
    strcpy(str1, str);
    for (int i = 0; i < strlen(str1); i++)
    {
        if (isspace(str1[i]))
        {
            str1[i] = '\0';
        }
    }
    printf("\nString without whitespaces: %s\n", str1);

    return 0;
}