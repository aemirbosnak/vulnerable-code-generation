//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[256];
    printf("Enter a color name: ");
    scanf("%s", input);

    int r, g, b, a;
    switch (input[0])
    {
        case 'R':
            r = 255;
            g = 0;
            b = 0;
            a = 255;
            break;
        case 'G':
            r = 0;
            g = 255;
            b = 0;
            a = 255;
            break;
        case 'B':
            r = 0;
            g = 0;
            b = 255;
            a = 255;
            break;
        case 'Y':
            r = 255;
            g = 255;
            b = 0;
            a = 255;
            break;
        case 'C':
            r = 255;
            g = 0;
            b = 255;
            a = 255;
            break;
        default:
            printf("Invalid input.\n");
            exit(1);
    }

    printf("Color code: RGB(%d, %d, %d), Alpha: %d\n", r, g, b, a);

    return 0;
}