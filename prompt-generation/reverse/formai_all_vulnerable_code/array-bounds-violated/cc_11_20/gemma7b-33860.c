//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    printf("Enter text: ");
    fgets(text, 100, stdin);

    char morse[100][4] = {
        {'.---', '-..---', '-..', '.'},
        {'..---', '--.----', '---..', '.'},
        {'.---.', '-..', '--.', '---'},
        {'.---', '....', '-..', '.'},
        {'.---', '-..', '--.', '---'}
    };

    for (int i = 0; text[i] != '\0'; i++)
    {
        switch (text[i])
        {
            case 'a':
            case 'A':
                printf("%s ", morse[0][0]);
                break;
            case 'b':
            case 'B':
                printf("%s ", morse[0][1]);
                break;
            case 'c':
            case 'C':
                printf("%s ", morse[0][2]);
                break;
            case 'd':
            case 'D':
                printf("%s ", morse[0][3]);
                break;
            case 'e':
            case 'E':
                printf("%s ", morse[0][4]);
                break;
            default:
                printf("Unknown character: %c ", text[i]);
                break;
        }
    }

    printf("\n");

    return 0;
}