//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a given string
void reverse(char* str)
{
    int len = strlen(str);
    for(int i=0, j=len-1; i<len/2; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to count the number of vowels in a string
int countVowels(char* str)
{
    int len = strlen(str);
    int count = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
           str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') 
        {
            count++;
        }
    }
    return count;
}

// Function to remove all occurrences of a given character from a string
void removeChar(char* str, char c)
{
    int len = strlen(str);
    int new_len = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] != c)
        {
            str[new_len++] = str[i];
        }
    }
    str[new_len] = '\0';
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%[^\n]", str);
    getchar();

    printf("\nOriginal string: %s", str);

    // Reverse the string
    reverse(str);
    printf("\nReversed string: %s", str);

    // Count number of vowels in the string
    int vowel_count = countVowels(str);
    printf("\nNumber of vowels in the string: %d", vowel_count);

    // Remove a character from the string
    char c;
    printf("\nEnter a character to remove: ");
    scanf("%c", &c);
    removeChar(str, c);
    printf("\nString after removing '%c': %s", c, str);

    printf("\n");

    return 0;
}