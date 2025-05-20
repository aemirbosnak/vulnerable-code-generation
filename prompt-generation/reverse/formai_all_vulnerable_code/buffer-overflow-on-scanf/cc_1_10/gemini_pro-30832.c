//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: complete
/*
 * Created by Pavan Goyal on 2nd December, 2020.
 * Purpose: C Program to print "S" Pattern using functions.
 * Note: This program also includes some basic string manipulation functions.
 */

#include <stdio.h>
#include <string.h>

// Function to print "S" Pattern using for loops
void printSPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n/2 + 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

// Function to convert a string to Uppercase
void toUpperCase(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

// Function to convert a string to Lowercase
void toLowerCase(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

// Main Function
int main()
{
    int n;
    char str[100];

    printf("Enter a number: ");
    scanf("%d", &n);

    printSPattern(n);

    printf("\nEnter a string: ");
    scanf(" %[^\n]s", str);

    printf("\nUppercase: %s", str);
    toUpperCase(str);
    printf("\nLowercase: %s", str);
    toLowerCase(str);

    printf("\n");
    
    return 0;
}