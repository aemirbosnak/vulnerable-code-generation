//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse Code equivalent of English Alphabet and numerals
const char* MorseCode[] =
{
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   // A-I
    ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",  // J-R
    "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--..",        // S-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", // 0-7
    "---..", "----." // 8-9
};

char toMorseCode(char c)
{
    if (isalpha(c))
    {
        return MorseCode[toupper(c) - 'A'];
    }
    else if (isdigit(c))
    {
        return MorseCode[c - '0' + 26];
    }
    else if (isspace(c))
    {
        return '/';
    }
    return '\0';
}

int main()
{
    printf("\n*** C Text to Morse Code Conversion ***\n");

    char text[1000];
    printf("Enter text (MAX 1000 characters): ");
    fgets(text, 1000, stdin);

    int textLength = strlen(text);
    if (text[textLength - 1] == '\n')
    {
        text[textLength - 1] = '\0';
    }

    printf("\nMorse Code Equivalent: ");
    for (int i = 0; i < textLength; i++)
    {
        char c = toMorseCode(text[i]);
        if (c != '\0')
        {
            printf("%s ", c);
        }
    }
    printf("\n\n");
    return 0;
}