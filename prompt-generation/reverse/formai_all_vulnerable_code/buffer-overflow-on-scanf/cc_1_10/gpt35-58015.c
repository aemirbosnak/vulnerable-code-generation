//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str)
{
    // Declare variables
    int i, j, len;
    
    // Get length of input string
    len = strlen(str);
    
    // Check if the string is empty or has only one character
    if (len == 0 || len == 1)
    {
        return 1;
    }
    
    // Check if the string is a palindrome
    for (i=0, j=len-1; i<j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    // Declare variables
    char str[100];
    
    // Get input from user
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Check if input string is a palindrome and print result
    if (isPalindrome(str))
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }
    
    return 0;
}