//FormAI DATASET v1.0 Category: Image Editor ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char name[20], namecopy[20];
    int choice, length, index, red, green, blue, x, y;
    FILE *input, *output;
    unsigned char header[54];
    unsigned char *pixels, *pixcopy;
    long int width, height, newsize;
    const short int bpp = 24;

    // load the image 
    printf("Enter the filename (include the extension): ");
    scanf("%s", name);

    input = fopen(name, "rb");
    if (input == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    // read the header
    fread(header, sizeof(unsigned char), 54, input);

    // extract the width and height from the header
    width = *(long int*)&header[18];
    height = *(long int*)&header[22];

    // calculate the length of the pixel array
    length = bpp/8 * height * width;

    // allocate the pixel array
    pixels = (unsigned char*)malloc(length);

    // copy the pixel array
    fread(pixels, sizeof(unsigned char), length, input);
    fclose(input);

    // make a copy of the pixel array
    pixcopy = (unsigned char*)malloc(length);
    memcpy(pixcopy, pixels, length);

    // print menu
    printf("What would you like to do?\n");
    printf("1. Make a grayscale image\n");
    printf("2. Add a red filter\n");
    printf("3. Add a green filter\n");
    printf("4. Add a blue filter\n");
    printf("5. Add a custom filter\n");
    printf("6. Save and exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    while (choice != 6)
    {
        // switch case based on user's choice
        switch (choice)
        {
            case 1:
                // make the image grayscale by averaging the RGB values
                for (int i = 0; i < length; i += 3)
                {
                    red = pixels[i];
                    green = pixels[i+1];
                    blue = pixels[i+2];
                    pixels[i] = pixels[i+1] = pixels[i+2] = (red + green + blue)/3;
                }
                printf("Grayscale complete.\n");
                break;

            case 2:
                // add a red filter by setting all green and blue values to 0
                for (int i = 0; i < length; i += 3)
                {
                    pixels[i+1] = pixels[i+2] = 0;
                }
                printf("Red filter complete.\n");
                break;

            case 3:
                // add a green filter by setting all red and blue values to 0
                for (int i = 0; i < length; i += 3)
                {
                    pixels[i] = pixels[i+2] = 0;
                }
                printf("Green filter complete.\n");
                break;

            case 4:
                // add a blue filter by setting all red and green values to 0
                for (int i = 0; i < length; i += 3)
                {
                    pixels[i] = pixels[i+1] = 0;
                }
                printf("Blue filter complete.\n");
                break;

            case 5:
                // get user input for custom filter values
                printf("Enter the red filter value (0-255): ");
                scanf("%d", &red);
                printf("Enter the green filter value (0-255): ");
                scanf("%d", &green);
                printf("Enter the blue filter value (0-255): ");
                scanf("%d", &blue);

                // add the custom filter by setting each pixel to the user's input values
                for (int i = 0; i < length; i += 3)
                {
                    pixels[i] = red;
                    pixels[i+1] = green;
                    pixels[i+2] = blue;
                }
                printf("Custom filter complete.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        // print the menu again
        printf("What would you like to do?\n");
        printf("1. Make a grayscale image\n");
        printf("2. Add a red filter\n");
        printf("3. Add a green filter\n");
        printf("4. Add a blue filter\n");
        printf("5. Add a custom filter\n");
        printf("6. Save and exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
    }

    // ask the user to enter a new name for the modified image
    printf("Enter a new filename for the modified image (include the extension): ");
    scanf("%s", namecopy);

    // open the output file and write the modified image
    output = fopen(namecopy, "wb");
    if (output == NULL)
    {
        printf("Output file could not be created.\n");
        return 0;
    }
    fwrite(header, sizeof(unsigned char), 54, output);
    fwrite(pixels, sizeof(unsigned char), length, output);
    fclose(output);

    printf("Image saved as %s.\n", namecopy);

    // free the memory used for the pixel arrays
    free(pixels);
    free(pixcopy);

    return 0;
}