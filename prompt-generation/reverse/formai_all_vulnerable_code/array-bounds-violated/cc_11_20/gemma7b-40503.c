//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100] = "The quick brown fox jumps over the lazy dog.";
    int i = 0;
    char color[20] = "";

    printf("The mystery begins...\n\n");

    while (str[i] != '\0')
    {
        switch (str[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                color[i] = 'R';
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                color[i] = 'G';
                break;
            case 'f':
            case 'h':
            case 'j':
            case 'l':
            case 'n':
                color[i] = 'B';
                break;
            default:
                color[i] = 'Y';
                break;
        }

        i++;
    }

    printf("The decoded message is:\n\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        printf("%c", color[i]);
    }

    printf("\nThe mystery is solved!\n");

    return 0;
}