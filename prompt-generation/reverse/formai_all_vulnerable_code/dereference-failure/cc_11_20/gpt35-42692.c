//FormAI DATASET v1.0 Category: Image Editor ; Style: curious
// Curious Image Editor Program

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PIXEL_VALUE 255

int main()
{
    printf("Welcome to the Curious Image Editor Program!\n");
    printf("Please enter the name of the image file you wish to edit: ");
    
    char filename[20];
    scanf("%s", filename);
    
    printf("Opening file...\n");
    
    FILE *fp = fopen(filename, "rb");
    
    if (fp == NULL)
    {
        printf("File could not be opened.\n");
        exit(1);
    }
    
    // Determine file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    
    printf("File opened successfully (size: %ld bytes).\n", size);

    // Allocate memory for image data
    unsigned char *data = (unsigned char*) malloc(size);
    
    if (data == NULL)
    {
        printf("Memory could not be allocated.\n");
        exit(1);
    }

    // Read image data into memory
    fread(data, sizeof(unsigned char), size, fp);

    // Close file
    fclose(fp);

    // Ask user for editing mode
    int mode;
    do
    {
        printf("Please select an editing mode:\n");
        printf("1. Brightness adjustment\n");
        printf("2. Grayscale conversion\n");
        printf("3. Invert colors\n");
        printf("4. Quit program\n");

        printf("Selection: ");
        scanf("%d", &mode);

        // Process user selection
        switch (mode)
        {
            case 1:
                printf("Please enter a brightness adjustment value (-255 to 255): ");
                int brightness;
                scanf("%d", &brightness);

                for (int i = 0; i < size; i++)
                {
                    int pixel = (int)data[i] + brightness;
                    data[i] = (unsigned char) (pixel < 0 ? 0 : pixel > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : pixel);
                }

                printf("Brightness adjustment applied successfully.\n");
                break;

            case 2:
                for (int i = 0; i < size; i += 3)
                {
                    unsigned char gray = (unsigned char) ((int)data[i] * 0.21f + (int)data[i+1] * 0.72f + (int)data[i+2] * 0.07f);
                    data[i] = data[i+1] = data[i+2] = gray;
                }

                printf("Grayscale conversion applied successfully.\n");
                break;

            case 3:
                for (int i = 0; i < size; i++)
                {
                    data[i] = (unsigned char) (MAX_PIXEL_VALUE - (int)data[i]);
                }

                printf("Colors inverted successfully.\n");
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid selection. Please enter a value between 1 and 4.\n");
                break;
        }

    } while (mode != 4);

    // Ask user for output filename
    printf("Please enter the name of the output file: ");
    scanf("%s", filename);

    // Write edited image data to file
    fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        printf("File could not be created.\n");
        exit(1);
    }

    fwrite(data, sizeof(unsigned char), size, fp);
    fclose(fp);

    printf("File saved successfully!\n");

    // Free allocated memory
    free(data);

    return 0;
}