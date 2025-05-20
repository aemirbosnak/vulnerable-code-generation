//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Function to reverse a string
void reverseString(char* str)
{
    int length = strlen(str);
    char* reversed = (char*)malloc(length+1); // Allocate memory for reversed string
    int i,j;
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        reversed[j] = tolower(str[i]); // Convert to lowercase and store in reversed string
    }
    reversed[j] = '\0'; // Add null terminator to end of reversed string
    printf("Reversed string: %s\n", reversed);
    free(reversed); // Free memory allocated for reversed string
}

// Function to check if a string is a palindrome
int isPalindrome(char* str)
{
    int length = strlen(str);
    char* reversed = (char*)malloc(length+1); // Allocate memory for reversed string
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        if(tolower(str[i])!= tolower(str[j])) // Compare characters after converting to lowercase
        {
            free(reversed); // Free memory allocated for reversed string
            return 0; // String is not a palindrome
        }
    }
    free(reversed); // Free memory allocated for reversed string
    return 1; // String is a palindrome
}

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Reverse the input string
    reverseString(inputString);

    // Check if the reversed string is a palindrome
    if(isPalindrome(inputString))
    {
        printf("The input string is a palindrome.\n");
    }
    else
    {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}