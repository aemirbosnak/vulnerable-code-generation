//FormAI DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LEN 100
#define MAX_OPTION_LEN 50

/* Function declarations */
void print_menu();
void run_editor(char* filename);
void save_changes(char* filename, int* image, int rows, int cols);
void apply_grayscale(int* image, int rows, int cols);
void apply_negative(int* image, int rows, int cols);
void apply_brightness(int* image, int rows, int cols, int value);

/* Main program */
int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Welcome to the Image Editor!\nPlease enter the name of the file you want to edit: ");
    scanf("%s", filename);
    run_editor(filename);
    return 0;
}

/* Prints the menu of editing options */
void print_menu() {
    printf("\n\n");
    printf("1. Grayscale\n");
    printf("2. Negative\n");
    printf("3. Adjust brightness\n");
    printf("4. Save changes\n");
    printf("5. Quit\n");
}

/* Runs the editor on a given image file */
void run_editor(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s!\n", filename);
        return;
    }
    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);
    int* image = malloc(rows*cols*sizeof(int));
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            fscanf(file, "%d", &image[i*cols+j]);
        }
    }
    fclose(file);
    printf("Image loaded successfully!\n");
    int choice = -1;
    while (choice != 5) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                apply_grayscale(image, rows, cols);
                break;
            case 2:
                apply_negative(image, rows, cols);
                break;
            case 3:
                printf("Enter brightness adjustment value (-255 to 255): ");
                int value;
                scanf("%d", &value);
                apply_brightness(image, rows, cols, value);
                break;
            case 4:
                save_changes(filename, image, rows, cols);
                printf("Changes saved successfully!\n");
                break;
            case 5:
                printf("Exiting Image Editor...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    free(image);
}

/* Saves the edits made to the image to the original file */
void save_changes(char* filename, int* image, int rows, int cols) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "%d %d\n", rows, cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            fprintf(file, "%d ", image[i*cols+j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

/* Converts the image to grayscale */
void apply_grayscale(int* image, int rows, int cols) {
    for (int i=0; i<rows*cols; i++) {
        int avg = (image[i]>>16 & 0xFF) + (image[i]>>8 & 0xFF) + (image[i] & 0xFF);
        avg /= 3;
        image[i] = (avg << 16) | (avg << 8) | avg;
    }
    printf("Applied grayscale!\n");
}

/* Converts the image to its negative */
void apply_negative(int* image, int rows, int cols) {
    for (int i=0; i<rows*cols; i++) {
        int red = 255 - (image[i]>>16 & 0xFF);
        int green = 255 - (image[i]>>8 & 0xFF);
        int blue = 255 - (image[i] & 0xFF);
        image[i] = (red << 16) | (green << 8) | blue;
    }
    printf("Applied negative!\n");
}

/* Adjusts the brightness of the image by a given value */
void apply_brightness(int* image, int rows, int cols, int value) {
    if (value < -255 || value > 255) {
        printf("Invalid brightness adjustment value!\n");
        return;
    }
    for (int i=0; i<rows*cols; i++) {
        int red = image[i]>>16 & 0xFF;
        int green = image[i]>>8 & 0xFF;
        int blue = image[i] & 0xFF;
        red += value;
        green += value;
        blue += value;
        if (red < 0) red = 0;
        if (green < 0) green = 0;
        if (blue < 0) blue = 0;
        if (red > 255) red = 255;
        if (green > 255) green = 255;
        if (blue > 255) blue = 255;
        image[i] = (red << 16) | (green << 8) | blue;
    }
    printf("Applied brightness adjustment!\n");
}