//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX_SIZE 1000

//function to check if a string is a palindrome
bool isPalindrome(char str[])
{
    int len = strlen(str);
    for(int i=0;i<len/2;i++)
    {
        if(tolower(str[i])!=tolower(str[len-1-i]))
        {
            return false;
        }
    }
    return true;
}

//function to remove non-alphanumeric characters from a string
void removeNonAlphanumeric(char str[])
{
    int len = strlen(str);
    char temp[MAX_SIZE];
    int j = 0;
    for(int i=0;i<len;i++)
    {
        if(isalnum(str[i]))
        {
            temp[j++] = tolower(str[i]);
        }
    }
    temp[j] = '\0';
    strcpy(str,temp);
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s",str);
    removeNonAlphanumeric(str);
    if(isPalindrome(str))
    {
        printf("%s is a palindrome\n",str);
    }
    else
    {
        printf("%s is not a palindrome\n",str);
    }
    return 0;
}