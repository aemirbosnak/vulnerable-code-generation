//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
// Welcome to the Palindrome Checker Program!
// This program checks if the input given by the user is a palindrome or not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

// Function to check if the given string is a palindrome or not
int check_palindrome(char *string)
{
    int i, j;
    int string_length = strlen(string);

    for (i = 0, j = string_length - 1; i < j; i++, j--)
    {
        // Convert the characters to lowercase and ignore spaces and punctuation
        while (!isalpha(string[i])) i++;
        while (!isalpha(string[j])) j--;
        if (tolower(string[i]) != tolower(string[j]))
        {
            // If characters do not match, it is not a palindrome
            return 0;
        }
    }
    // If all characters matched, it is a palindrome
    return 1;
}

int main()
{
    // Print a warm and welcoming message
    printf("Welcome to the Palindrome Checker Program!\n");

    // Create an array to hold the input string from the user
    char input_string[MAX];

    // Ask the user to enter a string to check if it is a palindrome or not
    printf("Please enter a string to check if it is a palindrome or not: ");

    // Read the input string from the user
    fgets(input_string, MAX, stdin);

    // Remove the newline character at the end of the input string
    input_string[strlen(input_string) - 1] = '\0';

    // Check if the input string is a palindrome or not
    if (check_palindrome(input_string))
    {
        // If it is a palindrome, print a happy message
        printf("Hooray! \"%s\" is a palindrome!", input_string);
    }
    else
    {
        // If it is NOT a palindrome, print a sad message
        printf("Sorry, \"%s\" is not a palindrome.", input_string);
    }

    // Exit the program
    return 0;
}