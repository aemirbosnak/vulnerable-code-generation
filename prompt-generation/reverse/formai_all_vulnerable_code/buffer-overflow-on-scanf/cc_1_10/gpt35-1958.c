//FormAI DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* Welcome to our amazing image editor!
 * This program allows you to load and edit images in C language!
 * We've included a few sample images for you to test out the program.
 */

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

void printMenu();
void loadFromFile(char filename[], int image[][MAX_WIDTH], int *height, int *width);
void inverseImage(int image[][MAX_WIDTH], int height, int width);
void applyThreshold(int image[][MAX_WIDTH], int height, int width, int thresholdValue);
void printImage(int image[][MAX_WIDTH], int height, int width);
void saveToFile(char filename[], int image[][MAX_WIDTH], int height, int width);

int main() 
{
    int image[MAX_HEIGHT][MAX_WIDTH];
    int height, width;
    char filename[20];
    int choice, thresholdValue;

    printf("Welcome to our amazing image editor!\n");
    printf("Please enter the filename of the image you wish to edit: ");
    scanf("%s", filename);
    loadFromFile(filename, image, &height, &width);

    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Applying inverse filter to image...\n");
                inverseImage(image, height, width);
                break;
            case 2:
                printf("Enter threshold value: ");
                scanf("%d", &thresholdValue);
                printf("Applying threshold filter to image...\n");
                applyThreshold(image, height, width, thresholdValue);
                break;
            case 3:
                printf("Printing image...\n");
                printImage(image, height, width);
                break;
            case 4:
                printf("Enter new filename: ");
                scanf("%s", filename);
                printf("Saving image...\n");
                saveToFile(filename, image, height, width);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void printMenu() 
{
    printf("\nMenu:\n");
    printf("1. Inverse filter\n");
    printf("2. Threshold filter\n");
    printf("3. Print image\n");
    printf("4. Save image\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

void loadFromFile(char filename[], int image[][MAX_WIDTH], int *height, int *width)
{
    FILE *file;
    int row, col;

    file = fopen(filename, "r");

    if (file) {
        fscanf(file, "%d %d", height, width);
        for (row = 0; row < *height; row++) {
            for (col = 0; col < *width; col++) {
                fscanf(file, "%d", &image[row][col]);
            }
        }
        fclose(file);
        printf("File loaded successfully.\n");
    } else {
        printf("Error loading file.\n");
    }
}

void inverseImage(int image[][MAX_WIDTH], int height, int width)
{
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            image[row][col] = 255 - image[row][col];
        }
    }
    printf("Inverse filter applied.\n");
}

void applyThreshold(int image[][MAX_WIDTH], int height, int width, int thresholdValue)
{
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            if (image[row][col] < thresholdValue) {
                image[row][col] = 0;
            } else {
                image[row][col] = 255;
            }
        }
    }
    printf("Threshold filter applied.\n");
}

void printImage(int image[][MAX_WIDTH], int height, int width)
{
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            if (image[row][col] > 127) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void saveToFile(char filename[], int image[][MAX_WIDTH], int height, int width)
{
    FILE *file;
    int row, col;

    file = fopen(filename, "w");

    if (file) {
        fprintf(file, "%d %d\n", height, width);
        for (row = 0; row < height; row++) {
            for (col = 0; col < width; col++) {
                fprintf(file, "%d ", image[row][col]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
        printf("File saved successfully.\n");
    } else {
        printf("Error saving file.\n");
    }
}