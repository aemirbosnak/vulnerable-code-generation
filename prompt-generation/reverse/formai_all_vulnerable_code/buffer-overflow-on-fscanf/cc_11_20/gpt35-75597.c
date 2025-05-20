//FormAI DATASET v1.0 Category: Image Editor ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 20
#define MAX_IMAGE_SIZE 100

int main()
{
    char file_name[MAX_FILE_NAME_LENGTH];
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width, height, choice, new_color;
    FILE *fptr;

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    fptr = fopen(file_name, "r");

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fscanf(fptr, "%d %d", &width, &height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf(fptr, "%d", &image[i][j]);
        }
    }

    fclose(fptr);

    printf("What would you like to do with the image?\n");
    printf("1. Invert colors\n");
    printf("2. Change a specific color\n");
    printf("3. Save the image\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j] = 255 - image[i][j];
            }
        }
        printf("Colors inverted!\n");
        break;
    case 2:
        printf("Which color would you like to change?");
        scanf("%d", &choice);
        printf("What is the new color value?");
        scanf("%d", &new_color);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (image[i][j] == choice)
                {
                    image[i][j] = new_color;
                }
            }
        }
        printf("Selected color changed!\n");
        break;
    case 3:
        fptr = fopen(file_name, "w");
        fprintf(fptr, "%d %d\n", width, height);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                fprintf(fptr, "%d ", image[i][j]);
            }
            fprintf(fptr, "\n");
        }
        fclose(fptr);
        printf("Image saved!\n");
        break;
    default:
        printf("Invalid choice!");
        break;
    }

    return 0;
}