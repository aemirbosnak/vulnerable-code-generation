//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

char reverseString(char *);  // This function would be used to reverse the given string
int checkPalindrome(char *, int);  // This function would be used to check if the given string is palindrome or not

int main()
{
    char inputString[MAX_LENGTH];
    printf("*** Welcome to the Palindrome Checker Program ***\n");
    printf("\nEnter the string to check for Palindrome: ");
    scanf("%s", inputString);

    int length = strlen(inputString);
    
    if(checkPalindrome(inputString, length))
    {
        printf("\n%s is a Palindrome.\n\n", inputString);
    }
    else
    {
        printf("\n%s is not a Palindrome.\n\n", inputString);
    }
}

char reverseString(char *str)
{
    int i, j;
    char ch;
    int n = strlen(str);

    for(i=0, j=n-1; i<j; i++, j--)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }

    return *str;
}

int checkPalindrome(char *str, int length)
{
    char reversedString[MAX_LENGTH];

    strcpy(reversedString, str);
    reverseString(reversedString);
    
    int i, count=0;

    for(i=0; i<length; i++)
    {
        if(str[i] != reversedString[i])
        {
            count++;
            break;
        }
    }

    if(count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}