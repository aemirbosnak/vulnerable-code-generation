//FormAI DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MAX_FILENAME_LENGTH 100

void readImage(char fileName[], int *width, int *height, int *maxPixelValue, int ***imageData) {
    FILE *filePointer;
    int i, j;
	
    filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("Error: Unable to open file %s\n", fileName);
        exit(1);
    }
	
    char format[3];
    fscanf(filePointer, "%s", format);
    if (format[0] != 'P' || format[1] != '3') {
        printf("Error: Invalid file format.\n");
        exit(1);
    }
	
    fscanf(filePointer, "%d %d", width, height);
    fscanf(filePointer, "%d", maxPixelValue);
	
    *imageData = malloc(*height * sizeof(int *));
    for (i = 0; i < *height; i++) {
        (*imageData)[i] = malloc((*width)* 3 * sizeof(int));
        for (j = 0; j < (*width) * 3; j++) {
            fscanf(filePointer, "%d", &((*imageData)[i][j]));
        }
    }
	
    fclose(filePointer);
}

void writeImage(char fileName[], int width, int height, int maxPixelValue, int **imageData) {
    FILE *filePointer;
    int i, j;
	
    filePointer = fopen(fileName, "w");
    if (filePointer == NULL) {
        printf("Error: Unable to create file %s\n", fileName);
        exit(1);
    }
	
    fprintf(filePointer, "P3\n%d %d\n%d\n", width, height, maxPixelValue);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width * 3; j++) {
            fprintf(filePointer, "%d ", imageData[i][j]);
        }
        fprintf(filePointer, "\n");
    }
	
    fclose(filePointer);
}

void invertImage(int width, int height, int **imageData) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width * 3; j++) {
            imageData[i][j] = MAX_PIXEL_VALUE - imageData[i][j];
        }
    }
}

void grayscaleImage(int width, int height, int **imageData) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width * 3; j += 3) {
            int grayscaleValue = (imageData[i][j] + imageData[i][j+1] + imageData[i][j+2]) / 3;
            imageData[i][j] = grayscaleValue;
            imageData[i][j+1] = grayscaleValue;
            imageData[i][j+2] = grayscaleValue;
        }
    }
}

int main() {
    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter the name of the file to edit: ");
    scanf("%s", fileName);
	
    int width, height, maxPixelValue, **imageData;
    readImage(fileName, &width, &height, &maxPixelValue, &imageData);
	
    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Invert image\n");
        printf("2. Convert to grayscale\n");
        printf("3. Save changes and exit\n");
        scanf("%d", &choice);
		
        switch(choice) {
            case 1:
                invertImage(width, height, imageData);
                printf("Image inverted.\n");
                break;
            case 2:
                grayscaleImage(width, height, imageData);
                printf("Image converted to grayscale.\n");
                break;
            case 3:
                printf("Enter the name of the new file: ");
                scanf("%s", fileName);
                writeImage(fileName, width, height, maxPixelValue, imageData);
                printf("Changes saved to %s\n", fileName);
                exit(0);
                break;
            default:
                printf("Invalid choice. Please type 1, 2, or 3.\n");
        }
    }
	
    return 0;
}