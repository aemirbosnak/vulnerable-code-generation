//FormAI DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PIXEL_VALUE 255

// Function to read the image from file
int** read_image(char filename[], int* width, int* height) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error reading file\n");
        exit(1);
    }

    char buffer[MAX_FILENAME_LENGTH];
    fgets(buffer, MAX_FILENAME_LENGTH, file); // PGM format
    fgets(buffer, MAX_FILENAME_LENGTH, file); // Comment line
    fscanf(file, "%d %d",&(*width),&(*height)); // Width and height
    fgets(buffer, MAX_FILENAME_LENGTH, file); // Max pixel value

    int** image = (int**) malloc((*height) * sizeof(int*));
    for (int i = 0; i < (*height); i++) {
        image[i] = (int*) malloc((*width) * sizeof(int));
        for (int j = 0; j < (*width); j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }

    fclose(file);
    return image;
}

// Function to write the image to file
void write_image(char filename[], int** image, int width, int height) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error writing file\n");
        exit(1);
    }

    fprintf(file, "P2\n"); // PGM format
    fprintf(file, "# Created by Linux Image Editor\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", MAX_PIXEL_VALUE);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to invert the colors of the image
void invert_colors(int** image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = MAX_PIXEL_VALUE - image[i][j];
        }
    }
}

// Function to swap two colors of the image
void swap_colors(int** image, int width, int height, int color1, int color2) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j] == color1) {
                image[i][j] = color2;
            } else if (image[i][j] == color2) {
                image[i][j] = color1;
            }
        }
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    int width, height;
    int** image = read_image(filename, &width, &height);
    printf("Image (%d x %d) read from file\n", width, height);

    int choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1 - Invert colors\n");
        printf("2 - Swap two colors\n");
        printf("3 - Save and exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invert_colors(image, width, height);
                printf("Colors inverted\n");
                break;
            case 2:
                printf("Enter the first color to swap: ");
                int color1;
                scanf("%d", &color1);
                printf("Enter the second color to swap: ");
                int color2;
                scanf("%d", &color2);
                swap_colors(image, width, height, color1, color2);
                printf("Colors swapped\n");
                break;
            case 3:
                printf("Enter the file name to save: ");
                char save_filename[MAX_FILENAME_LENGTH];
                scanf("%s", save_filename);
                write_image(save_filename, image, width, height);
                printf("Image saved to file %s\n", save_filename);
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 3);

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}