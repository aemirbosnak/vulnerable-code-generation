//FormAI DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if given string is palindrome
int isPalindrome(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str1[100], str2[100]; // Declare two strings of length 100
    int choice;

    printf("Enter your first string: ");
    scanf("%s", str1);

    printf("Enter your second string: ");
    scanf("%s", str2);

    printf("Choose what you want to do with the strings:\n");
    printf("1. Concatenate them\n");
    printf("2. Replace all occurrences of a letter in first string with a letter from second string\n");
    printf("3. Check if first string is a palindrome\n");
    printf("4. Swap first half of first string with second half of second string\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Concatenated string: %s%s\n", str1, str2);
            break;

        case 2:
            printf("Enter the letter you want to replace: ");
            char x, y;
            scanf(" %c", &x);
            printf("Enter the letter to replace %c with: ", x);
            scanf(" %c", &y);
            for (int i = 0; i < strlen(str1); i++)
            {
                if (str1[i] == x)
                {
                    str1[i] = y;
                }
            }
            printf("New string: %s\n", str1);
            break;

        case 3:
            if (isPalindrome(str1))
            {
                printf("The first string is a palindrome\n");
            }
            else
            {
                printf("The first string is not a palindrome\n");
            }
            break;

        case 4:
            if (strlen(str1) % 2 != 0 || strlen(str2) % 2 != 0)
            {
                printf("The strings must both have an even length\n");
                exit(0);
            }
            for (int i = 0, j = strlen(str2) / 2; i < j; i++, j++)
            {
                char temp = str1[i];
                str1[i] = str2[j];
                str2[j] = temp;
            }
            printf("New first string: %s\n", str1);
            printf("New second string: %s\n", str2);
            break;

        default:
            printf("Invalid choice! Please try again\n");
    }

    return 0;
}