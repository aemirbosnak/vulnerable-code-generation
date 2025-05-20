//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function to check if a string is a palindrome
int isPalindrome(char *str)
{
    int len = strlen(str);
    //creating a new string to store the reversed version of the original string
    char revStr[len+1];
    int j = 0;
    //loop through the original string backwards and store each character in the new string
    for(int i = len-1; i >= 0; i--)
    {
        if(isalpha(str[i])) //check if the character is a letter
        {
            revStr[j++] = tolower(str[i]); //convert the letter to lowercase and add it to the new string
        }
    }
    revStr[j] = '\0'; //add a null terminator to the end of the new string
    
    //compare the original string with the reversed string
    if(strcmp(str,revStr) == 0)
    {
        return 1; //the strings are equal, meaning the original string is a palindrome
    }
    else
    {
        return 0; //the strings are not equal, meaning the original string is not a palindrome
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str,100,stdin); //read input from user
    
    //remove newline character that gets added to the end of the input string by fgets()
    if (str[strlen(str)-1] == '\n')
    {
        str[strlen(str)-1] = '\0';
    }
    
    //call isPalindrome() function to check if the input string is a palindrome
    if(isPalindrome(str))
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }
    
    return 0;
}