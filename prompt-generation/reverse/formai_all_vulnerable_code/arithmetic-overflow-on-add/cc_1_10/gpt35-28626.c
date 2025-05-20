//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option, width, height;
    char filename[20];
    FILE *fptr;

    printf("Welcome to Cyber Image Editor!\n");
    printf("Please choose an option:\n");
    printf("1. Create new image file\n");
    printf("2. Modify existing image file\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Enter image filename: ");
            scanf("%s", filename);
            printf("Enter image width: ");
            scanf("%d", &width);
            printf("Enter image height: ");
            scanf("%d", &height);

            fptr = fopen(filename, "w");
            if(fptr == NULL)
            {
                printf("Error creating file!\n");
                exit(1);
            }

            fprintf(fptr, "P3\n%d %d\n255\n", width, height);

            int r, g, b, x, y;
            for(y=0; y<height; y++)
            {
                for(x=0; x<width; x++)
                {
                    r = rand() % 255;
                    g = rand() % 255;
                    b = rand() % 255;
                    fprintf(fptr, "%d %d %d ", r, g, b);
                }
                fprintf(fptr, "\n");
            }

            printf("New image file created! Filename: %s\n", filename);
            fclose(fptr);
            break;

        case 2:
            printf("Enter image filename: ");
            scanf("%s", filename);

            fptr = fopen(filename, "r+");
            if(fptr == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }

            char c;
            do {
                c = getc(fptr);
                putchar(c);
            } while(c != EOF);

            printf("Enter x and y coordinates to modify (in format x,y): ");
            scanf("%d,%d", &x, &y);

            printf("Enter new color values (in format r,g,b): ");
            scanf("%d,%d,%d", &r, &g, &b);

            fseek(fptr, ((width*y)+x)*6, SEEK_SET);
            fprintf(fptr, "%d %d %d ", r, g, b);

            printf("Image file modified! Filename: %s\n", filename);
            fclose(fptr);
            break;

        default:
            printf("Invalid option selected!\n");
            exit(1);
    }

    return 0;
}