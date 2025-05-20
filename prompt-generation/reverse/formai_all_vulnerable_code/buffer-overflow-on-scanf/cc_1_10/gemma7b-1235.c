//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char temp;

    while (num)
    {
        temp = num % 10;
        str[i++] = temp + '0';
        num /= 10;
    }
    str[i] = '\0';
}

int main()
{
    int image_width, image_height;
    char **image_data;

    printf("Enter image width: ");
    scanf("%d", &image_width);

    printf("Enter image height: ");
    scanf("%d", &image_height);

    image_data = (char **)malloc(image_height * sizeof(char *) + 1);
    for (int h = 0; h < image_height; h++)
    {
        image_data[h] = (char *)malloc(image_width * sizeof(char) + 1);
    }

    printf("Enter image data (separated by spaces): ");
    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            scanf("%d ", &image_data[h][w]);
        }
    }

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            itoa(image_data[h][w], image_data[h][w] + '0');
        }
    }

    printf("Image converted to ASCII art:\n");
    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            printf("%c ", image_data[h][w]);
        }
        printf("\n");
    }

    free(image_data);

    return 0;
}