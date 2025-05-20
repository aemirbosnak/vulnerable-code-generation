//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char output[100];

    printf("Enter a sentence in C Cat Language:");
    scanf("%s", input);

    // Convert the input sentence into uppercase
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] -= 32;
        }
    }

    // Replace all vowels with their corresponding vowel sound in C Cat Language
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == 'a')
        {
            output[i] = 'A';
        }
        else if (input[i] == 'e')
        {
            output[i] = 'E';
        }
        else if (input[i] == 'i')
        {
            output[i] = 'I';
        }
        else if (input[i] == 'o')
        {
            output[i] = 'O';
        }
        else if (input[i] == 'u')
        {
            output[i] = 'U';
        }
        else
        {
            output[i] = input[i];
        }
    }

    // Add a C Cat Language exclamation mark at the end of the output sentence
    output[strlen(output)] = '!';

    // Print the translated sentence in C Cat Language
    printf("Your sentence translated into C Cat Language is:\n");
    printf("%s\n", output);

    return 0;
}