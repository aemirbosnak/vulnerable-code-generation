//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str)
{
    int len = strlen(str);
    char *rev = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
        rev[len - 1 - i] = str[i];
    printf("Reversed string: %s\n", rev);
}

// Function to count the number of vowels in a string
int countVowels(char *str)
{
    int count = 0;
    for (int i = 0; str[i]!= '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            count++;
    }
    return count;
}

// Function to print a star pattern
void printStarPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverse(str);
    printf("Reversed string: %s\n", str);

    int count = countVowels(str);
    printf("Number of vowels: %d\n", count);

    printStarPattern(6);

    return 0;
}