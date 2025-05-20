//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define CAT_SOUND "Meow!"

int main()
{
    char input[100];
    printf("Enter a phrase in the C Cat Language: ");
    scanf("%s", input);

    // Translate the phrase
    char translated[200];
    int i = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        switch (input[i])
        {
            case 'a':
                translated[i] = 'A';
                break;
            case 'e':
                translated[i] = 'E';
                break;
            case 'i':
                translated[i] = 'I';
                break;
            case 'o':
                translated[i] = 'O';
                break;
            case 'u':
                translated[i] = 'U';
                break;
            default:
                translated[i] = input[i];
                break;
        }

        if (translated[i] != '\0')
        {
            translated[i + 1] = CAT_SOUND;
        }
    }

    // Print the translated phrase
    printf("Your phrase in C Cat Language is: ");
    printf("%s\n", translated);

    return 0;
}