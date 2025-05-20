//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str)
{
    // Get the length of the string
    int len = strlen(str);

    // Check if the string is empty or has only one character
    if (len <= 1)
        return 1;

    // Create a pointer to the first character of the string
    char *ptr1 = str;

    // Create a pointer to the last character of the string
    char *ptr2 = str + len - 1;

    // Compare the characters at the two pointers
    while (ptr1 < ptr2)
    {
        if (*ptr1 != *ptr2)
            return 0;

        // Move the pointers closer to each other
        ptr1++;
        ptr2--;
    }

    // If the loop completes, the string is a palindrome
    return 1;
}

// Driver code to test the isPalindrome function
int main()
{
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    int is_palindrome = isPalindrome(str);

    // Print the result
    if (is_palindrome)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}