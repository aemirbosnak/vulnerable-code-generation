//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void convertToASCII(unsigned char pixel)
{
    switch (pixel)
    {
        case 0:
            printf(" ");
            break;
        case 1:
            printf(".");
            break;
        case 2:
            printf("..");
            break;
        case 3:
            printf("...");
            break;
        case 4:
            printf("....");
            break;
        case 5:
            printf(".....");
            break;
        case 6:
            printf("......");
            break;
        case 7:
            printf(".......");
            break;
        case 8:
            printf("........");
            break;
        case 9:
            printf("*********");
            break;
    }
}

int main()
{
    unsigned char image[] = {
        0, 1, 1, 0, 0,
        1, 1, 1, 1, 0,
        1, 1, 1, 1, 1,
        0, 0, 0, 1, 0,
        0, 0, 0, 0, 0
    };

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            convertToASCII(image[y * 6 + x]);
        }

        printf("\n");
    }

    return 0;
}