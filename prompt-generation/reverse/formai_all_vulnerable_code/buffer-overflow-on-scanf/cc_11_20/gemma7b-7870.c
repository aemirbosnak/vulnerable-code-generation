//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char input[256];
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("Shocked C Color Code Converter\n\n");
    printf("Enter a color code (e.g. rgb, hex, hsl): ");
    scanf("%s", input);

    // Analyze the input color code
    for (i = 0; input[i] != '\0'; i++)
    {
        switch (input[i])
        {
            case 'r':
                printf("Red: ");
                scanf("%d", &n);
                break;
            case 'g':
                printf("Green: ");
                scanf("%d", &m);
                break;
            case 'b':
                printf("Blue: ");
                scanf("%d", &o);
                break;
            case 'h':
                printf("Hue: ");
                scanf("%d", &p);
                break;
            case 's':
                printf("Saturation: ");
                scanf("%d", &q);
                break;
            case 'l':
                printf("Lightness: ");
                scanf("%d", &r);
                break;
            default:
                printf("Invalid color code.\n");
                exit(1);
        }
    }

    // Convert the color code
    switch (input[0])
    {
        case 'r':
            printf("RGB: (%d, %d, %d)\n", n, m, o);
            break;
        case 'h':
            printf("HSV: (%d, %d, %d)\n", p, q, r);
            break;
        case 'x':
            printf("Hex: #%02x%02x%02x\n", n, m, o);
            break;
        default:
            printf("Invalid color code.\n");
            exit(1);
    }

    return;
}