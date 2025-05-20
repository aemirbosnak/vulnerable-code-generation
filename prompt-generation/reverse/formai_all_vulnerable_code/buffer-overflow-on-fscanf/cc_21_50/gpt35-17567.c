//FormAI DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_COLOR_VALUE 255

typedef struct {
    int red;
    int green;
    int blue;
} pixel;

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    int width, height, choice;
    pixel** image;

    printf("Enter the name of the image file: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error opening file. Aborting.\n");
        exit(EXIT_FAILURE);
    }

    // Reading and validating the header of the PPM file.
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        printf("Invalid file format. Aborting.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &width, &height);
    if (width <= 0 || height <= 0) {
        printf("Invalid image size. Aborting.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", &choice);
    if (choice != MAX_COLOR_VALUE) {
        printf("Invalid max color value. Aborting.\n");
        exit(EXIT_FAILURE);
    }

    // Allocating memory for the image.
    image = malloc(height * sizeof(pixel*));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(pixel));
    }

    // Reading the image data from the file.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image[i][j], sizeof(pixel), 1, file);
        }
    }

    fclose(file);

    // Editing the image.
    printf("\nImage editing options:\n1. Invert colors\n2. Grayscale conversion\n3. Increase brightness\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    image[i][j].red = MAX_COLOR_VALUE - image[i][j].red;
                    image[i][j].green = MAX_COLOR_VALUE - image[i][j].green;
                    image[i][j].blue = MAX_COLOR_VALUE - image[i][j].blue;
                }
            }
            break;

        case 2:
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    int avg = (image[i][j].red + image[i][j].green + image[i][j].blue) / 3;
                    image[i][j].red = avg;
                    image[i][j].green = avg;
                    image[i][j].blue = avg;
                }
            }
            break;

        case 3:
            printf("Enter the amount by which you want to increase the brightness: ");
            int brightness_increase;
            scanf("%d", &brightness_increase);

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    int new_red = image[i][j].red + brightness_increase;
                    int new_green = image[i][j].green + brightness_increase;
                    int new_blue = image[i][j].blue + brightness_increase;

                    image[i][j].red = (new_red > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : new_red;
                    image[i][j].green = (new_green > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : new_green;
                    image[i][j].blue = (new_blue > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : new_blue;
                }
            }
            break;

        default:
            printf("Invalid choice. Aborting.\n");
            exit(EXIT_FAILURE);
    }

    // Writing the edited image to a new file.
    char new_file_name[MAX_FILE_NAME_SIZE];
    printf("\nEnter the name of the new image file (including extension): ");
    scanf("%s", new_file_name);

    file = fopen(new_file_name, "wb");
    if (file == NULL) {
        printf("Error creating new file. Aborting.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n%d %d\n%d\n", width, height, MAX_COLOR_VALUE);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&image[i][j], sizeof(pixel), 1, file);
        }
    }

    fclose(file);

    // Freeing the memory allocated for the image.
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    printf("\nImage edited successfully and saved to %s.\n", new_file_name);

    return 0;
}