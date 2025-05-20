//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];
    
    printf("Please enter some text: ");
    scanf("%[^\n]s", text); // Read input until new line character
    
    printf("The text you entered is: %s\n", text);
    
    int count = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
        {
            count++; // Count the number of spaces in the input text
        }
    }
    printf("The input text contains %d spaces.\n", count);
    
    // Reverse the input text
    char reversed[1000];
    int index = 0;
    for(int i = strlen(text) - 1; i >= 0; i--)
    {
        reversed[index++] = text[i]; // Copy characters from input to reversed in reverse order
    }
    reversed[index] = '\0'; // Add null character at the end to terminate string
    printf("The reversed text is: %s\n", reversed);
    
    // Convert input text to uppercase
    char uppercase[1000];
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z') // Check if character is lowercase
        {
            uppercase[i] = text[i] - 32; // Convert lowercase to uppercase using ASCII value
        }
        else
        {
            uppercase[i] = text[i]; // Copy character as is
        }
    }
    uppercase[strlen(text)] = '\0'; // Add null character at the end to terminate string
    printf("The uppercase text is: %s\n", uppercase);
    
    // Count the number of vowels in the input text
    int vowels = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U')
        {
            vowels++; // Count the number of vowels in the input text
        }
    }
    printf("The input text contains %d vowels.\n", vowels);
    
    // Remove all the vowels from the input text
    char consonants[1000];
    index = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(!(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U'))
        {
            consonants[index++] = text[i]; // Copy character to consonants array if it is not a vowel
        }
    }
    consonants[index] = '\0'; // Add null character at the end to terminate string
    printf("The input text with vowels removed is: %s\n", consonants);
    
    // Check if the input text is a palindrome
    int isPalindrome = 1; // Assume the text is palindrome initially
    for(int i = 0; i < strlen(text) / 2; i++)
    {
        if(text[i] != text[strlen(text) - i - 1])
        {
            isPalindrome = 0; // Set to 0 if there is a mismatch
            break; // No need to check further if there is a mismatch
        }
    }
    if(isPalindrome)
    {
        printf("The input text is a palindrome.\n");
    }
    else
    {
        printf("The input text is not a palindrome.\n");
    }
    
    return 0;
}