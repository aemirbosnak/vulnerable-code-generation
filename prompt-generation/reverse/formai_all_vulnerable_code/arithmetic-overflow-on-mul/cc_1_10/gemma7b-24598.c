//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void itoa(int n, char *s);

int main()
{
    int img_width, img_height;
    int **img_data;
    char **ascii_art;

    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    img_data = (int **)malloc(img_height * sizeof(int *));
    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = (int *)malloc(img_width * sizeof(int));
    }

    ascii_art = (char **)malloc(img_height * sizeof(char *));
    for (int h = 0; h < img_height; h++)
    {
        ascii_art[h] = (char *)malloc(img_width * sizeof(char));
    }

    // Get image data
    printf("Enter image data (separated by commas): ");
    char image_data[MAX_WIDTH * img_height];
    scanf("%s", image_data);

    // Convert image data to ASCII art
    int i = 0;
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            img_data[h][w] = atoi(&image_data[i]);
            ascii_art[h][w] = img_data[h][w] + 32;
            i++;
        }
    }

    // Print ASCII art
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    free(img_data);
    free(ascii_art);

    return 0;
}

void itoa(int n, char *s)
{
    int i = 0;
    char num[11];

    do
    {
        num[i++] = n % 10 + 48;
        n /= 10;
    } while (n);

    num[i] = '\0';
    strcpy(s, num);
}