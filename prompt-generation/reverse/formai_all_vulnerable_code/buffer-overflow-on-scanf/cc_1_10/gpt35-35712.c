//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

// Alien language characters
char alien_language[] = {'#', '!', '@', '^', '*', '<', '>', '?'};

void alien_language_translator(char input[], int length);

int main()
{
    char input[100];
    printf("Enter a string to translate into alien language: ");
    scanf("%[^\n]", &input);   // scan a string with spaces until a newline character

    alien_language_translator(input, strlen(input));

    return 0;
}

void alien_language_translator(char input[], int length)
{
    printf("Alien Language Translation: ");
    for (int i = 0; i < length; i++)
    {
        int ascii_code = (int)input[i];

        // check if the character is a lowercase alphabet
        if (ascii_code >= 97 && ascii_code <= 122)
        {
            int alien_code = ascii_code - 97;   // convert to 0-25 range
            printf("%c", alien_language[alien_code]);
        }
        // check if the character is an uppercase alphabet
        else if (ascii_code >= 65 && ascii_code <= 90)
        {
            int alien_code = ascii_code - 65;   // convert to 0-25 range
            printf("%c", toupper(alien_language[alien_code]));
        }
        // check if the character is a number
        else if (ascii_code >= 48 && ascii_code <= 57)
        {
            printf("%c", alien_language[ascii_code - 48 + 6]);   // convert to 6-15 range
        }
        // check if the character is a space
        else if (ascii_code == 32)
        {
            printf("%c", alien_language[0]);
        }
        else
        {
            printf("%c", input[i]);   // print the character as it is
        }
    }
}