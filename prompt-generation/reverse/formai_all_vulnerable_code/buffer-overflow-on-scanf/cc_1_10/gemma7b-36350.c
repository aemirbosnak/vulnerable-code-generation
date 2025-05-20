//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char tmp;

    while (num)
    {
        tmp = num % 10;
        str[i++] = tmp + '0';
        num /= 10;
    }

    str[i] = '\0';
}

int main()
{
    int image_width, image_height, pixel_value;
    char *image_ascii;

    printf("Enter image width: ");
    scanf("%d", &image_width);

    printf("Enter image height: ");
    scanf("%d", &image_height);

    image_ascii = malloc(image_width * image_height);

    printf("Enter pixel value: ");
    scanf("%d", &pixel_value);

    for (int y = 0; y < image_height; y++)
    {
        for (int x = 0; x < image_width; x++)
        {
            image_ascii[y * image_width + x] = pixel_value + '0';
        }
    }

    printf("Image ASCII art:\n");
    for (int y = 0; y < image_height; y++)
    {
        for (int x = 0; x < image_width; x++)
        {
            printf("%c ", image_ascii[y * image_width + x]);
        }
        printf("\n");
    }

    free(image_ascii);

    return 0;
}