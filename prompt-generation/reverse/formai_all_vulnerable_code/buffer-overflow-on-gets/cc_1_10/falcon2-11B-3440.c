//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to capitalize a string
void capitalizeString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
}

// Function to count the number of vowels in a string
int countVowels(char *str)
{
    int count = 0;
    for (int i = 0; str[i]!= '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }
    return count;
}

// Function to find the length of the longest palindrome in a string
int findLongestPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int k = 0;
            while (str[i + k] == str[j - k] && k < (j - i) / 2)
            {
                k++;
            }
            if (k > 1)
            {
                return k;
            }
        }
    }
    return -1;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Reverse the string
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Capitalize the string
    capitalizeString(str);
    printf("Capitalized string: %s\n", str);

    // Count the number of vowels in the string
    int vowelCount = countVowels(str);
    printf("Number of vowels: %d\n", vowelCount);

    // Find the length of the longest palindrome in the string
    int longestPalindromeLength = findLongestPalindrome(str);
    printf("Length of the longest palindrome: %d\n", longestPalindromeLength);

    return 0;
}