//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[11];

    if (n < 0)
    {
        num[0] = '-';
        n = -n;
    }

    do
    {
        num[i++] = n % 10 + '0';
        n /= 10;
    } while (n);

    num[i] = '\0';

    strcpy(s, num);
}

int main()
{
    char image[1024];
    int x, y, r, g, b;

    printf("Enter image dimensions (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter RGB values (r, g, b): ");
    scanf("%d %d %d", &r, &g, &b);

    printf("Enter image data (separated by commas): ");
    scanf("%s", image);

    for (int i = 0; i < x * y; i++)
    {
        int pixel = image[i] - '0';

        itoa(pixel, image);

        printf("%s ", image);
    }

    printf("\n");

    return 0;
}