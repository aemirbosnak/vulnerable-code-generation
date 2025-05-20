//FormAI DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 100

// Function declaration
void openFile();

// Global variables
FILE *fp = NULL;
char fileName[MAX_FILE_NAME];

int main() {
    int op = 0;

    // Welcome message
    printf("Welcome to the Image Editor!\n");

    // Prompt user for file name
    openFile();

    // Menu
    while (op != 4) {
        printf("\n1. Grayscale\n2. Invert colors\n3. Blur\n4. Exit\nChoose an option: ");
        scanf("%d", &op);

        switch(op) {
            case 1: // Grayscale
                printf("\nConverting to grayscale...");

                // Read image pixel by pixel
                char pixel[3];
                int r, g, b;
                while (fread(pixel, sizeof(char), 3, fp)) {
                    r = pixel[0];
                    g = pixel[1];
                    b = pixel[2];

                    // Calculate grayscale value
                    int grayscale = (0.3 * r) + (0.59 * g) + (0.11 * b);

                    // Set new pixel values
                    pixel[0] = grayscale;
                    pixel[1] = grayscale;
                    pixel[2] = grayscale;

                    // Write new pixel values to file
                    fseek(fp, -3, SEEK_CUR);
                    fwrite(pixel, sizeof(char), 3, fp);
                }

                printf("\nConversion to grayscale complete.");
                break;

            case 2: // Invert colors
                printf("\nInverting colors...");

                // Read image pixel by pixel
                while (fread(pixel, sizeof(char), 3, fp)) {
                    // Invert pixel values
                    pixel[0] = 255 - pixel[0];
                    pixel[1] = 255 - pixel[1];
                    pixel[2] = 255 - pixel[2];

                    // Write new pixel values to file
                    fseek(fp, -3, SEEK_CUR);
                    fwrite(pixel, sizeof(char), 3, fp);
                }

                printf("\nColor inversion complete.");
                break;

            case 3: // Blur
                printf("\nBlurring...");

                // Read image pixel by pixel
                int i, j;
                char pixels[9][3];
                while (fread(pixel, sizeof(char), 3, fp)) {
                    // Store surrounding pixels
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            if (j == 1 && i == 1) {
                                // Current pixel, skip
                                continue;
                            }

                            fread(pixels[i*3+j], sizeof(char), 3, fp);
                            fseek(fp, -3, SEEK_CUR);
                        }
                    }

                    // Average out pixel values
                    int r = 0, g = 0, b = 0;
                    for (i = 0; i < 9; i++) {
                        r += pixels[i][0];
                        g += pixels[i][1];
                        b += pixels[i][2];
                    }
                    r /= 9;
                    g /= 9;
                    b /= 9;

                    // Write new pixel values to file
                    pixel[0] = r;
                    pixel[1] = g;
                    pixel[2] = b;
                    fseek(fp, -3, SEEK_CUR);
                    fwrite(pixel, sizeof(char), 3, fp);
                }

                printf("\nBlur effect complete.");
                break;

            case 4: // Exit
                printf("\nExiting program...\n");
                fclose(fp);
                break;

            default: // Invalid option
                printf("\nPlease enter a valid option.\n");
        }

        // Reset file pointer to beginning
        rewind(fp);
    }

    return 0;
}

void openFile() {
    while (fp == NULL) {
        printf("\nEnter file name: ");
        scanf("%s", fileName);

        fp = fopen(fileName, "r+");

        if (fp == NULL) {
            printf("\nFile does not exist or cannot be opened. Please try again.\n");
        }
    }
}