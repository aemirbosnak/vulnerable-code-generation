//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int isPalindrome(char *input);

int main()
{
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input))
    {
        printf("The input string is a palindrome.\n");
    }
    else
    {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char *input)
{
    int length = strlen(input);
    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        // Ignore non-alphanumeric characters
        while (i < length &&!isalnum(input[i]))
        {
            i++;
        }

        // Ignore non-alphanumeric characters
        while (j >= 0 &&!isalnum(input[j]))
        {
            j--;
        }

        // Compare characters
        if (tolower(input[i])!= tolower(input[j]))
        {
            return 0;
        }

        // Move pointers closer to each other
        i++;
        j--;
    }

    return 1;
}