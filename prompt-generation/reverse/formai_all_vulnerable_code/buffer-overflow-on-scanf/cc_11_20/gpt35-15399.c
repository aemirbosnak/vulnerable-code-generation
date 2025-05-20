//FormAI DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[20], ch, choice;
    int width, height, num_pixels, i;
    FILE *fptr;

    printf("Welcome to the C Image Editor!\n");
    printf("Please enter the filename of the image you'd like to edit: ");
    scanf("%s", filename);
    fptr = fopen(filename, "rb");

    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        printf("Would you like to create a new file instead? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y')
        {
            fptr = fopen(filename, "wb");

            if (fptr == NULL)
            {
                printf("Error creating file.\n");
                exit(1);
            }
            else
            {
                printf("File created successfully.\n");
                printf("Please enter the width of the image (in pixels): ");
                scanf("%d", &width);

                printf("Please enter the height of the image (in pixels): ");
                scanf("%d", &height);

                fwrite(&width, sizeof(int), 1, fptr);
                fwrite(&height, sizeof(int), 1, fptr);
                num_pixels = width * height;

                for (i = 0; i < num_pixels; i++)
                {
                    fwrite(&ch, sizeof(char), 1, fptr);
                }
				
                fclose(fptr);
                printf("New image created with dimensions %d x %d.\n", width, height);
            }
        }
        else
        {
            exit(1);
        }
    }
    else
    {
        fread(&width, sizeof(int), 1, fptr);
        fread(&height, sizeof(int), 1, fptr);
        printf("Image loaded successfully with dimensions %d x %d.\n", width, height);
    }

    printf("What would you like to do with the image?\n");
    printf("1. Increase brightness\n");
    printf("2. Decrease brightness\n");
    printf("3. Convert to grayscale\n");
    printf("4. Invert colors\n");
    printf("5. Save and exit\n");

    while (1)
    {
        printf("Enter your choice (1-5):\n");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':
                printf("Increasing brightness...\n");
                fseek(fptr, 2 * sizeof(int), SEEK_SET);
                num_pixels = width * height;

                for (i = 0; i < num_pixels; i++)
                {
                    fread(&ch, sizeof(char), 1, fptr);
                    ch += 10;
                    fwrite(&ch, sizeof(char), 1, fptr);
                }

                printf("Brightness increased successfully.\n");
                break;

            case '2':
                printf("Decreasing brightness...\n");
                fseek(fptr, 2 * sizeof(int), SEEK_SET);
                num_pixels = width * height;

                for (i = 0; i < num_pixels; i++)
                {
                    fread(&ch, sizeof(char), 1, fptr);
                    ch -= 10;
                    fwrite(&ch, sizeof(char), 1, fptr);
                }

                printf("Brightness decreased successfully.\n");
                break;

            case '3':
                printf("Converting to grayscale...\n");
                fseek(fptr, 2 * sizeof(int), SEEK_SET);
                num_pixels = width * height;

                for (i = 0; i < num_pixels; i++)
                {
                    fread(&ch, sizeof(char), 1, fptr);
                    ch = (ch * 0.21 + ch * 0.72 + ch * 0.07) / 3;
                    fwrite(&ch, sizeof(char), 1, fptr);
                }

                printf("Conversion to grayscale successful.\n");
                break;

            case '4':
                printf("Inverting colors...\n");
                fseek(fptr, 2 * sizeof(int), SEEK_SET);
                num_pixels = width * height;

                for (i = 0; i < num_pixels; i++)
                {
                    fread(&ch, sizeof(char), 1, fptr);
                    ch = 255 - ch;
                    fwrite(&ch, sizeof(char), 1, fptr);
                }

                printf("Colors inverted successfully.\n");
                break;

            case '5':
                printf("Saving image and exiting...\n");
                fclose(fptr);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}