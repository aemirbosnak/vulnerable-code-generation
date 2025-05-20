//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, k;
    char a[100], b[100], c[100];

    printf("Enter text: ");
    scanf("%s", a);

    for (i = 0; a[i] != '\0'; i++)
    {
        switch (a[i])
        {
            case 'a':
            case 'A':
                b[i] = '4';
                break;
            case 'b':
            case 'B':
                b[i] = '5';
                break;
            case 'c':
            case 'C':
                b[i] = '6';
                break;
            case 'd':
            case 'D':
                b[i] = '7';
                break;
            case 'e':
            case 'E':
                b[i] = '8';
                break;
            case 'f':
            case 'F':
                b[i] = '9';
                break;
            default:
                b[i] = a[i];
                break;
        }
    }

    printf("ASCII art:\n");
    for (k = 0; b[k] != '\0'; k++)
    {
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 40; j++)
            {
                c[i * 40 + j] = '*';
            }
        }

        c[0] = b[k];
        printf("%s\n", c);
    }

    return 0;
}