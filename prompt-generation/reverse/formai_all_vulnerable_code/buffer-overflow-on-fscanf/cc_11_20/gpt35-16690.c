//FormAI DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[100], ch, option[10];
    FILE *fp;
    int i, j, height, width, brightness, max_brightness;
    unsigned char image[1024][1024];

    printf("\nEnter the filename (with .pgm extension): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\nCould not open file.");
        exit(0);
    }

    fscanf(fp, "%s", option);
    fscanf(fp, "%d %d %d", &width, &height, &max_brightness);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fscanf(fp, "%c", &ch); // read space or newline character
            fscanf(fp, "%c", &ch); // read actual pixel value
            image[i][j] = ch;
        }
    }

    fclose(fp);

    printf("\nImage details:");
    printf("\n    Width: %d", width);
    printf("\n    Height: %d", height);
    printf("\n    Max Brightness: %d", max_brightness);

    do
    {
        printf("\n\nMenu:\n1. Increase Brightness\n2. Decrease Brightness\n3. Save Image\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &i);

        switch (i)
        {
            case 1:
                printf("\nEnter the amount by which the brightness should be increased (between 1 and %d): ", max_brightness);
                scanf("%d", &brightness);

                for (i = 0; i < height; i++)
                {
                    for (j = 0; j < width; j++)
                    {
                        if (image[i][j] + brightness > max_brightness)
                            image[i][j] = max_brightness;
                        else
                            image[i][j] += brightness;
                    }
                }
                break;
            case 2:
                printf("\nEnter the amount by which the brightness should be decreased (between 1 and %d): ", max_brightness);
                scanf("%d", &brightness);

                for (i = 0; i < height; i++)
                {
                    for (j = 0; j < width; j++)
                    {
                        if (image[i][j] - brightness < 0)
                            image[i][j] = 0;
                        else
                            image[i][j] -= brightness;
                    }
                }
                break;
            case 3:
                printf("\nEnter the filename (with .pgm extension) to save the modified image: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");
                if (fp == NULL)
                {
                    printf("\nCould not create file.");
                    break;
                }

                fprintf(fp, "%s\n%d %d\n%d\n", option, width, height, max_brightness);

                for (i = 0; i < height; i++)
                {
                    for (j = 0; j < width; j++)
                    {
                        fprintf(fp, "%c", image[i][j]);
                    }
                    fprintf(fp, "\n");
                }

                fclose(fp);

                printf("\nModified image saved successfully!");
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid option. Try again.");
                break;
        }

    } while (i != 4);

    return 0;
}