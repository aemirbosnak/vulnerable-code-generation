//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
// Morse code conversion program

#include <stdio.h>
#include <string.h>

// Define Morse code mapping
const char *morse_code[4] = {".-", "-...", "-..", "."};

int main()
{
    char text[20];
    int i;

    // Get text from user
    printf("Enter text: ");
    scanf("%s", text);

    // Convert text to Morse code
    for (i = 0; text[i] != '\0'; i++)
    {
        switch (text[i])
        {
            case 'a':
            case 'A':
                printf("%s ", morse_code[0]);
                break;
            case 'b':
            case 'B':
                printf("%s ", morse_code[1]);
                break;
            case 'c':
            case 'C':
                printf("%s ", morse_code[2]);
                break;
            case 'd':
            case 'D':
                printf("%s ", morse_code[3]);
                break;
            default:
                printf("Invalid character");
                break;
        }
    }

    // Print Morse code
    printf("\nMorse code: ");
    for (i = 0; text[i] != '\0'; i++)
    {
        printf("%s ", morse_code[text[i] - 'a']);
    }

    return 0;
}