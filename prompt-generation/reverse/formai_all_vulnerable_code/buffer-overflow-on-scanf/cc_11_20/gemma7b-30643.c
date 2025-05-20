//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[256];
    int i = 0;

    printf("Enter a word: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
            case 'a':
            case 'A':
                str[i] = '4';
                break;
            case 'e':
            case 'E':
                str[i] = '5';
                break;
            case 'i':
            case 'I':
                str[i] = '6';
                break;
            case 'o':
            case 'O':
                str[i] = '7';
                break;
            case 'u':
            case 'U':
                str[i] = '8';
                break;
            case 'y':
            case 'Y':
                str[i] = '9';
                break;
            default:
                str[i] = str[i] - 32;
                break;
        }
    }

    printf("Your modified word is: %s", str);

    return 0;
}