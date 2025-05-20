//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char str[])
{
    // Convert string to lower case for comparison
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(tolower(str[i])!= tolower(str[len-i-1]))
            return 0;
    }
    return 1;
}

// Function to check if a string is a palindrome, ignoring whitespace and punctuation
int isPalindromeIgnore(char str[])
{
    // Convert string to lower case for comparison
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(tolower(str[i])!= tolower(str[len-i-1]))
            return 0;
    }
    return 1;
}

// Function to check if a string is a palindrome, ignoring whitespace and punctuation
int isPalindromeIgnoreCase(char str[])
{
    // Convert string to lower case for comparison
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(tolower(str[i])!= tolower(str[len-i-1]))
            return 0;
    }
    return 1;
}

// Function to check if a string is a palindrome, ignoring whitespace and punctuation
int isPalindromeIgnoreCase2(char str[])
{
    // Convert string to lower case for comparison
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(tolower(str[i])!= tolower(str[len-i-1]))
            return 0;
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Check if the string is a palindrome
    if(isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    // Check if the string is a palindrome, ignoring whitespace and punctuation
    if(isPalindromeIgnore(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    // Check if the string is a palindrome, ignoring whitespace and punctuation
    if(isPalindromeIgnoreCase(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    // Check if the string is a palindrome, ignoring whitespace and punctuation
    if(isPalindromeIgnoreCase2(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}