//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program takes a string as input and performs various string manipulation
// operations on it, including:
// - Reversing the string
// - Converting the string to uppercase
// - Converting the string to lowercase
// - Finding the length of the string
// - Copying the string to another string
// - Concatenating two strings together
// - Comparing two strings
// - Searching for a substring within a string
// - Replacing a substring within a string

int main()
{
    // Get the input string from the user.
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Reverse the string.
    char reversedString[100];
    int i, len = strlen(inputString);
    for (i = 0; i < len; i++)
    {
        reversedString[i] = inputString[len - i - 1];
    }
    reversedString[len] = '\0';
    printf("Reversed string: %s\n", reversedString);

    // Convert the string to uppercase.
    char upperString[100];
    for (i = 0; i < len; i++)
    {
        upperString[i] = toupper(inputString[i]);
    }
    upperString[len] = '\0';
    printf("Uppercase string: %s\n", upperString);

    // Convert the string to lowercase.
    char lowerString[100];
    for (i = 0; i < len; i++)
    {
        lowerString[i] = tolower(inputString[i]);
    }
    lowerString[len] = '\0';
    printf("Lowercase string: %s\n", lowerString);

    // Find the length of the string.
    int length = strlen(inputString);
    printf("Length of the string: %d\n", length);

    // Copy the string to another string.
    char copiedString[100];
    strcpy(copiedString, inputString);
    printf("Copied string: %s\n", copiedString);

    // Concatenate two strings together.
    char concatenatedString[200];
    strcat(concatenatedString, inputString);
    strcat(concatenatedString, " world");
    printf("Concatenated string: %s\n", concatenatedString);

    // Compare two strings.
    char string1[] = "Hello";
    char string2[] = "World";
    int comparisonResult = strcmp(string1, string2);
    if (comparisonResult == 0)
    {
        printf("The two strings are equal.\n");
    }
    else if (comparisonResult < 0)
    {
        printf("The first string is less than the second string.\n");
    }
    else
    {
        printf("The first string is greater than the second string.\n");
    }

    // Search for a substring within a string.
    char substring[] = "llo";
    char *foundSubstring = strstr(inputString, substring);
    if (foundSubstring != NULL)
    {
        printf("The substring was found at position %d.\n", foundSubstring - inputString);
    }
    else
    {
        printf("The substring was not found.\n");
    }

    // Replace a substring within a string.
    char newSubstring[] = "World";
    char *replacedSubstring = strstr(inputString, substring);
    if (replacedSubstring != NULL)
    {
        strcpy(replacedSubstring, newSubstring);
        printf("The substring was replaced with the new substring.\n");
    }
    else
    {
        printf("The substring was not found.\n");
    }

    return 0;
}