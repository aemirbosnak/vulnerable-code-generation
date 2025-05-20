//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_string[256];
    char translated_string[256];

    printf("Enter a C Cat Language phrase: ");
    fgets(input_string, 256, stdin);

    // Convert the input string into uppercase
    for (int i = 0; input_string[i] != '\0'; i++)
    {
        if (input_string[i] >= 'a' && input_string[i] <= 'z')
        {
            input_string[i] -= 32;
        }
    }

    // Replace all vowels with their corresponding vowel sounds in the Morse code
    for (int i = 0; input_string[i] != '\0'; i++)
    {
        switch (input_string[i])
        {
            case 'a':
                translated_string[i] = '.----.';
                break;
            case 'e':
                translated_string[i] = '-..---';
                break;
            case 'i':
                translated_string[i] = '.---..';
                break;
            case 'o':
                translated_string[i] = '---..---';
                break;
            case 'u':
                translated_string[i] = '.---.';
                break;
        }
    }

    // Add punctuation marks to the translated string
    translated_string[strlen(translated_string) - 1] = '\0';
    strcat(translated_string, ".");

    // Print the translated string
    printf("Translated C Cat Language phrase: %s\n", translated_string);

    return 0;
}