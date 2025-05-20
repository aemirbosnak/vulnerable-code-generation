//FormAI DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_IMAGE_SIZE 1024

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the image file to edit: ");
    scanf("%s", filename);

    FILE* file_ptr = fopen(filename, "rb");
    if (!file_ptr) {
        printf("Error: Could not read image file.\n");
        return 1;
    }

    unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3];
    int image_width, image_height;
    fread(&image_width, sizeof(int), 1, file_ptr);
    fread(&image_height, sizeof(int), 1, file_ptr);
    fread(image, sizeof(unsigned char), MAX_IMAGE_SIZE * MAX_IMAGE_SIZE * 3, file_ptr);

    fclose(file_ptr);

    printf("The image has been loaded successfully. Its dimensions are %d x %d pixels.\n", image_width, image_height);
    printf("What operation would you like to perform?\n");
    printf("1. Convert to grayscale\n");
    printf("2. Invert colors\n");
    printf("3. Add border\n");
    printf("Enter your choice (1/2/3): ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Converting to grayscale...\n");
            for (int i = 0; i < image_height; i++) {
                for (int j = 0; j < image_width; j++) {
                    unsigned char r = image[i][j][0];
                    unsigned char g = image[i][j][1];
                    unsigned char b = image[i][j][2];
                    unsigned char gray = (r + g + b) / 3;
                    image[i][j][0] = gray;
                    image[i][j][1] = gray;
                    image[i][j][2] = gray;
                }
            }
            break;

        case 2:
            printf("Inverting colors...\n");
            for (int i = 0; i < image_height; i++) {
                for (int j = 0; j < image_width; j++) {
                    image[i][j][0] = 255 - image[i][j][0];
                    image[i][j][1] = 255 - image[i][j][1];
                    image[i][j][2] = 255 - image[i][j][2];
                }
            }
            break;

        case 3:
            printf("Adding border...\n");
            int border_width;
            printf("Enter the width of the border: ");
            scanf("%d", &border_width);
            for (int i = 0; i < image_height; i++) {
                for (int j = 0; j < image_width; j++) {
                    if (i < border_width || j < border_width || i >= image_height - border_width || j >= image_width - border_width) {
                        image[i][j][0] = 0;
                        image[i][j][1] = 0;
                        image[i][j][2] = 0;
                    }
                }
            }
            break;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    char new_filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the new image file: ");
    scanf("%s", new_filename);

    file_ptr = fopen(new_filename, "wb");
    if (!file_ptr) {
        printf("Error: Could not create new image file.\n");
        return 1;
    }

    fwrite(&image_width, sizeof(int), 1, file_ptr);
    fwrite(&image_height, sizeof(int), 1, file_ptr);
    fwrite(image, sizeof(unsigned char), MAX_IMAGE_SIZE * MAX_IMAGE_SIZE * 3, file_ptr);

    fclose(file_ptr);

    printf("The edited image has been saved as %s.\n", new_filename);

    return 0;
}