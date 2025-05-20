//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include<stdio.h>
#include<string.h>

void palindromeCheck(char str[]);

int main()
{
    char str[100];
    
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    
    //Call the palindromeCheck function
    palindromeCheck(str);
    
    return 0;
}

void palindromeCheck(char str[])
{
    int i, j;
    int len = strlen(str);
    int flag = 1;
    
    //Make all the characters lowercase to compare easily
    for(i=0; i<len; i++)
    {
        str[i] = tolower(str[i]);
    }
    
    //If the length of the string is odd, ignore the middle character for checking palindrome
    if(len%2 != 0)
    {
        for(i=0, j=len-1; i<j; i++, j--)
        {
            if(str[i] != str[j])
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        for(i=0, j=len-1; i<=j; i++, j--)
        {
            if(str[i] != str[j])
            {
                flag = 0;
                break;
            }
        }
    }
    
    //Display whether the string is a palindrome or not
    if(flag == 1)
    {
        printf("The string is a palindrome!\n");
    }
    else
    {
        printf("The string is not a palindrome!\n");
    }
}