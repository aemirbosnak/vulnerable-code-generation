//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//function to check if a string is a palindrome
int isPalindrome(char *str)
{
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(tolower(str[i])!= tolower(str[len-i-1]))
        {
            return 0;
        }
    }
    return 1;
}

//function to check if a string contains only alphabets
int containsOnlyAlphabets(char *str)
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(!isalpha(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

//function to check if a string is a virus
int isVirus(char *str)
{
    if(containsOnlyAlphabets(str) && isPalindrome(str))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char input[100];
    printf("Enter a string to check if it is a virus: ");
    scanf("%s", input);
    if(isVirus(input))
    {
        printf("The string is a virus.\n");
    }
    else
    {
        printf("The string is not a virus.\n");
    }
    return 0;
}