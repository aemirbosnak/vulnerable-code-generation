//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[10];

    if (n < 0)
    {
        s[0] = '-';
        n = -n;
    }
    else
    {
        s[0] = '+';
    }

    while (n)
    {
        num[i++] = n % 10 + '0';
        n /= 10;
    }

    num[i] = '\0';

    strcpy(s, num);
}

int main()
{
    char image[1024];
    int width, height;

    printf("Enter image width: ");
    scanf("%d", &width);

    printf("Enter image height: ");
    scanf("%d", &height);

    printf("Enter image data (separated by spaces): ");
    scanf("%s", image);

    // Convert image data to ASCII art
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel = image[x] * height + y;
            char color[10];

            itoa(pixel, color);

            printf("%c ", color[0]);
        }

        printf("\n");
    }

    return 0;
}