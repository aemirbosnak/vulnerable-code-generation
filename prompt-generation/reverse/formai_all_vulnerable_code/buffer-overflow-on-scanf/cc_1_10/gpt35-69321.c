//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Hi there! Let's check if a word is Palindrome!\n");
    printf("Enter a word: ");

    char word[100];
    scanf("%s", word); // assuming user inputs a word with no whitespace
    
    int left = 0;
    int right = strlen(word) - 1;
    int is_palindrome = 1; // boolean flag to determine if word is palindrome
    
    while (left < right)
    {
        // ignore non-alphabetic characters
        while (!isalpha(word[left]))
        {
            left++;
        }
        while (!isalpha(word[right]))
        {
            right--;
        }
    
        // compare alphabetic characters
        if (tolower(word[left]) != tolower(word[right]))
        {
            is_palindrome = 0;
            break;
        }
        
        left++;
        right--;
    }
    
    if (is_palindrome)
    {
        printf("\nHurray! The word you entered is a Palindrome! 🎉🎉🎉\n");
    }
    else
    {
        printf("\nOops! The word you entered is not a Palindrome. 😢\n");
    }
    
    return 0;
}