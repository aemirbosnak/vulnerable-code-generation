//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str)
{
    int length = strlen(str);
    for (int i = 0; i < length/2; i++)
    {
        if (tolower(str[i])!= tolower(str[length-i-1]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char input[MAX_LENGTH];
    char* temp;
    int length;

    printf("Welcome to the Happy Palindrome Checker!\n");
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    temp = strchr(input, '\n');
    if (temp!= NULL)
    {
        *temp = '\0';
    }

    // Remove leading/trailing whitespace
    temp = input;
    while (isspace(*temp))
    {
        temp++;
    }
    length = strlen(temp);
    while (isspace(temp[length-1]))
    {
        temp[length-1] = '\0';
        length--;
    }

    if (isPalindrome(temp))
    {
        printf("That's a palindrome! You're amazing!\n");
    }
    else
    {
        printf("Sorry, that's not a palindrome. But don't worry, you're still amazing!\n");
    }

    return 0;
}