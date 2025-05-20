//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scientific
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char string[MAX_SIZE]; // The string to be checked
    int i, j, length;
    int flag = 1; // Flag variable to check if the string is a palindrome or not
    
    printf("Enter a string: ");
    scanf("%[^\n]", string);
    
    length = strlen(string);
    
    // Convert the string to lower case
    for(i=0; i<length; i++)
    {
        string[i] = tolower(string[i]);
    }
    
    // Remove all the non-alphabetic characters from the string
    for(i=j=0; i<length; i++)
    {
        if(isalpha(string[i]))
        {
            string[j++] = string[i];
        }
    }
    
    string[j] = '\0'; // Null terminate the new string
    
    length = strlen(string); // Update the length of the new string after removing non-alphabetic characters
    
    // Check if the string is a palindrome
    for(i=0; i<length/2; i++)
    {
        if(string[i] != string[length-i-1])
        {
            flag = 0;
            break;
        }
    }
    
    if(flag)
    {
        printf("%s is a palindrome", string);
    }
    else
    {
        printf("%s is not a palindrome", string);
    }
    
    return 0;
}