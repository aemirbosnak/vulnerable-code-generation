//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int img_width, img_height;
    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    char **img_data = (char **)malloc(img_height * sizeof(char *) + 1);
    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = (char *)malloc(img_width * sizeof(char) + 1);
    }

    printf("Enter image data (separated by commas): ");
    char img_data_str[1000];
    scanf("%[^\n]%*c", img_data_str);

    char *img_data_ptr = img_data_str;
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            img_data[h][w] = atoi(img_data_ptr);
            img_data_ptr++;
        }
    }

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            switch (img_data[h][w])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("!");
                    break;
                case 2:
                    printf("$");
                    break;
                case 3:
                    printf("%");
                    break;
                case 4:
                    printf("#");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }

    free(img_data);

    return 0;
}