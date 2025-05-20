//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
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
    int img_width, img_height, pixel_value;
    char img_data[1024];

    printf("Enter image width:");
    scanf("%d", &img_width);

    printf("Enter image height:");
    scanf("%d", &img_height);

    printf("Enter pixel value:");
    scanf("%d", &pixel_value);

    img_data[0] = pixel_value;
    img_data[1] = pixel_value;
    img_data[2] = pixel_value;

    for (int y = 0; y < img_height; y++)
    {
        for (int x = 0; x < img_width; x++)
        {
            itoa(img_data[x * img_height + y], img_data + x * img_height + y);
        }
    }

    printf("Image data:\n");
    for (int y = 0; y < img_height; y++)
    {
        for (int x = 0; x < img_width; x++)
        {
            printf("%c ", img_data[x * img_height + y]);
        }
        printf("\n");
    }

    return 0;
}