//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Sherlock Holmes' Image Processing Toolkit

// Elementary, my dear Watson!
void printWelcome() {
    printf("Welcome to Sherlock Holmes' Image Processing Toolkit!\n");
    printf("Enter the command you wish to perform:\n");
    printf("1. Flip an image\n");
    printf("2. Change image brightness\n");
    printf("3. Change image contrast\n");
    printf("4. Quit\n");
}

// The game's afoot!
int main() {
    int choice;
    char filename[50];
    int i, j;
    unsigned char image[512][512];

    while (1) {
        printWelcome();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the image to flip: ");
                scanf("%s", filename);

                // Read the image from the file
                FILE *fp = fopen(filename, "rb");
                if (fp == NULL) {
                    printf("Error opening the image file!\n");
                    continue;
                }
                fread(image, sizeof(image), 1, fp);
                fclose(fp);

                // Flip the image vertically
                for (i = 0; i < 512; i++) {
                    for (j = 0; j < 256; j++) {
                        unsigned char temp = image[i][j];
                        image[i][j] = image[i][511 - j];
                        image[i][511 - j] = temp;
                    }
                }

                // Write the flipped image to a new file
                fp = fopen("flipped.bmp", "wb");
                if (fp == NULL) {
                    printf("Error writing the flipped image file!\n");
                    continue;
                }
                fwrite(image, sizeof(image), 1, fp);
                fclose(fp);

                printf("The image has been flipped vertically and saved to flipped.bmp.\n");
                break;

            case 2:
                printf("Enter the name of the image to change brightness: ");
                scanf("%s", filename);

                // Read the image from the file
                fp = fopen(filename, "rb");
                if (fp == NULL) {
                    printf("Error opening the image file!\n");
                    continue;
                }
                fread(image, sizeof(image), 1, fp);
                fclose(fp);

                // Adjust the brightness of the image
                int brightness;
                printf("Enter the brightness value (0-255): ");
                scanf("%d", &brightness);

                for (i = 0; i < 512; i++) {
                    for (j = 0; j < 512; j++) {
                        image[i][j] = image[i][j] + brightness;
                        if (image[i][j] > 255) {
                            image[i][j] = 255;
                        }
                    }
                }

                // Write the brightened image to a new file
                fp = fopen("brightened.bmp", "wb");
                if (fp == NULL) {
                    printf("Error writing the brightened image file!\n");
                    continue;
                }
                fwrite(image, sizeof(image), 1, fp);
                fclose(fp);

                printf("The image has been brightened and saved to brightened.bmp.\n");
                break;

            case 3:
                printf("Enter the name of the image to change contrast: ");
                scanf("%s", filename);

                // Read the image from the file
                fp = fopen(filename, "rb");
                if (fp == NULL) {
                    printf("Error opening the image file!\n");
                    continue;
                }
                fread(image, sizeof(image), 1, fp);
                fclose(fp);

                // Adjust the contrast of the image
                float contrast;
                printf("Enter the contrast value (0.0-2.0): ");
                scanf("%f", &contrast);

                for (i = 0; i < 512; i++) {
                    for (j = 0; j < 512; j++) {
                        image[i][j] = 128 + contrast * (image[i][j] - 128);
                        if (image[i][j] < 0) {
                            image[i][j] = 0;
                        } else if (image[i][j] > 255) {
                            image[i][j] = 255;
                        }
                    }
                }

                // Write the contrasted image to a new file
                fp = fopen("contrasted.bmp", "wb");
                if (fp == NULL) {
                    printf("Error writing the contrasted image file!\n");
                    continue;
                }
                fwrite(image, sizeof(image), 1, fp);
                fclose(fp);

                printf("The image has been contrasted and saved to contrasted.bmp.\n");
                break;

            case 4:
                printf("Thank you for using Sherlock Holmes' Image Processing Toolkit.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}