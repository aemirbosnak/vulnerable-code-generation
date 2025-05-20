//FormAI DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

//Function to read the image file
void readImage(char filename[], int image[MAX_WIDTH][MAX_HEIGHT], int* width, int* height) {
    FILE* infile;
    infile = fopen(filename, "r");
    fscanf(infile, "%d%d", width, height);
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(infile, "%d", &image[j][i]);
        }
    }
    fclose(infile);
}

//Function to write the image file
void writeImage(char filename[], int image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    FILE* outfile;
    outfile = fopen(filename, "w");
    fprintf(outfile, "%d %d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(outfile, "%d ", image[j][i]);
        }
        fprintf(outfile, "\n");
    }
    fclose(outfile);
}

//Function to add brightness to the image
void brightness(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height, int b) {
    int temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[j][i] + b;
            if (temp > 255) {
                image[j][i] = 255;
            }
            else if (temp < 0) {
                image[j][i] = 0;
            }
            else {
                image[j][i] = temp;
            }
        }
    }
}

//Function to convert the image to grayscale
void grayscale(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    int gray;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            gray = (int)(0.3 * image[j][i] + 0.59 * image[j][i] + 0.11 * image[j][i]);
            image[j][i] = gray;
        }
    }
}

//Function to blur the image
void blur(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height, int r) {
    int sum, count;
    int temp[MAX_WIDTH][MAX_HEIGHT];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sum = 0;
            count = 0;
            for (int m = i - r; m <= i + r; m++) {
                for (int n = j - r; n <= j + r; n++) {
                    if (m >= 0 && m < height && n >= 0 && n < width) {
                        sum += image[n][m];
                        count++;
                    }
                }
            }
            temp[j][i] = sum / count;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[j][i] = temp[j][i];
        }
    }
}

//Function to sharpen the image
void sharpen(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    int sum;
    int temp[MAX_WIDTH][MAX_HEIGHT];
    int kernel[3][3] = { {-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1} };
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sum = 0;
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    if (i + m >= 0 && i + m < height && j + n >= 0 && j + n < width) {
                        sum += kernel[m + 1][n + 1] * image[j + n][i + m];
                    }
                }
            }
            temp[j][i] = sum;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[j][i] = temp[j][i];
        }
    }
}

//Main function
int main() {
    int image[MAX_WIDTH][MAX_HEIGHT];
    int width, height, choice, b, r;
    char filename[100];
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    readImage(filename, image, &width, &height);
    printf("\nImage successfully loaded.\n");
    while (1) {
        printf("\n************ IMAGE EDITOR ************\n");
        printf("1. Add brightness\n");
        printf("2. Convert to grayscale\n");
        printf("3. Blur the image\n");
        printf("4. Sharpen the image\n");
        printf("5. Save the image\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the brightness value (-255 to 255): ");
            scanf("%d", &b);
            brightness(image, width, height, b);
            printf("Brightness added.\n");
            break;
        case 2:
            grayscale(image, width, height);
            printf("Image converted to grayscale.\n");
            break;
        case 3:
            printf("\nEnter the radius of blur: ");
            scanf("%d", &r);
            blur(image, width, height, r);
            printf("Image blurred.\n");
            break;
        case 4:
            sharpen(image, width, height);
            printf("Image sharpened.\n");
            break;
        case 5:
            printf("\nEnter the filename to save the image: ");
            scanf("%s", filename);
            writeImage(filename, image, width, height);
            printf("Image saved.\n");
            break;
        case 6:
            printf("\nThank you for using the Image Editor!\n");
            return 0;
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    }
    return 0;
}