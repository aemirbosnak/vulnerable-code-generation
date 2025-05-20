//Falcon-180B DATASET v1.0 Category: Text processing ; Style: light-weight
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_TEXT_LENGTH 1000

int main()
{
    char text[MAX_TEXT_LENGTH];
    int i, j;

    // Get input text from user
    printf("Enter the text: ");
    scanf("%[^\n]", text);

    // Remove leading and trailing white spaces
    int length = strlen(text);
    for (i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            memmove(&text[i], &text[i+1], length - i - 1);
            length--;
        }
    }
    text[length] = '\0';

    // Reverse the text
    for (i = 0, j = strlen(text) - 1; i < j; i++, j--)
    {
        char temp = text[i];
        text[i] = text[j];
        text[j] = temp;
    }

    // Convert all characters to uppercase
    for (i = 0; i < strlen(text); i++)
    {
        text[i] = toupper(text[i]);
    }

    // Count the number of words in the text
    int word_count = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            word_count++;
        }
    }

    // Count the number of characters in the text
    int char_count = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            char_count++;
        }
    }

    // Count the number of vowels in the text
    int vowel_count = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U' || text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
        {
            vowel_count++;
        }
    }

    // Output the results
    printf("Original text: %s\n", text);
    printf("Reversed text: %s\n", text);
    printf("Number of words: %d\n", word_count);
    printf("Number of characters: %d\n", char_count);
    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}