//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char num_str[11];

    sprintf(num_str, "%d", num);
    while (num_str[i] != '\0')
    {
        str[i] = num_str[i];
        i++;
    }
    str[i] = '\0';
}

int main()
{
    int r, c, pixel, red, green, blue;
    char **ascii_art;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    ascii_art = (char **)malloc(r * sizeof(char *));
    for (int i = 0; i < r; i++)
    {
        ascii_art[i] = (char *)malloc(c * sizeof(char));
    }

    printf("Enter the pixel value (red, green, blue): ");
    scanf("%d, %d, %d", &red, &green, &blue);

    pixel = red * 256 + green * 256 + blue;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ascii_art[i][j] = pixel;
        }
    }

    printf("Your ASCII art:\n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            itoa(ascii_art[i][j], &ascii_art[i][j]);
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}