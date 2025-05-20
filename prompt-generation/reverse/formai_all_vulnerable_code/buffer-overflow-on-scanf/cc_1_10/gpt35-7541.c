//FormAI DATASET v1.0 Category: Image Editor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void grayscale(unsigned char *imageData, int imageWidth, int imageHeight)
{
    int row, col, pixel, grayVal;
    for (row = 0; row < imageHeight; row++)
    {
        for (col = 0; col < imageWidth; col++)
        {
            pixel = (row * imageWidth) + col;
            grayVal = (imageData[pixel * 3] + imageData[pixel * 3 + 1] + imageData[pixel * 3 + 2]) / 3;
            imageData[pixel * 3] = grayVal;
            imageData[pixel * 3 + 1] = grayVal;
            imageData[pixel * 3 + 2] = grayVal;
        }
    }
}

void invert(unsigned char *imageData, int imageWidth, int imageHeight)
{
    int row, col, pixel;
    for (row = 0; row < imageHeight; row++)
    {
        for (col = 0; col < imageWidth; col++)
        {
            pixel = (row * imageWidth) + col;
            imageData[pixel * 3] = 255 - imageData[pixel * 3];
            imageData[pixel * 3 + 1] = 255 - imageData[pixel * 3 + 1];
            imageData[pixel * 3 + 2] = 255 - imageData[pixel * 3 + 2];
        }
    }
}

void blur(unsigned char *imageData, int imageWidth, int imageHeight)
{
    int row, col, pixel, i, j;
    int sumR, sumG, sumB, count;
    unsigned char *tempData = (unsigned char *) malloc(sizeof(unsigned char) * imageWidth * imageHeight * 3);
    memcpy(tempData, imageData, sizeof(unsigned char) * imageWidth * imageHeight * 3);
    for (row = 0; row < imageHeight; row++)
    {
        for (col = 0; col < imageWidth; col++)
        {
            pixel = (row * imageWidth) + col;
            sumR = sumG = sumB = count = 0;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (row + i >= 0 && col + j >= 0 && row + i < imageHeight && col + j < imageWidth)
                    {
                        sumR += tempData[((row + i) * imageWidth + col + j) * 3];
                        sumG += tempData[((row + i) * imageWidth + col + j) * 3 + 1];
                        sumB += tempData[((row + i) * imageWidth + col + j) * 3 + 2];
                        count++;
                    }
                }
            }
            imageData[pixel * 3] = sumR / count;
            imageData[pixel * 3 + 1] = sumG / count;
            imageData[pixel * 3 + 2] = sumB / count;
        }
    }
    free(tempData);
}

void brightness(unsigned char *imageData, int imageWidth, int imageHeight, int brightnessValue)
{
    int row, col, pixel;
    for (row = 0; row < imageHeight; row++)
    {
        for (col = 0; col < imageWidth; col++)
        {
            pixel = (row * imageWidth) + col;
            if (imageData[pixel * 3] + brightnessValue > 255)
            {
                imageData[pixel * 3] = 255;
            }
            else if (imageData[pixel * 3] + brightnessValue < 0)
            {
                imageData[pixel * 3] = 0;
            }
            else
            {
                imageData[pixel * 3] += brightnessValue;
            }
            if (imageData[pixel * 3 + 1] + brightnessValue > 255)
            {
                imageData[pixel * 3 + 1] = 255;
            }
            else if (imageData[pixel * 3 + 1] + brightnessValue < 0)
            {
                imageData[pixel * 3 + 1] = 0;
            }
            else
            {
                imageData[pixel * 3 + 1] += brightnessValue;
            }
            if (imageData[pixel * 3 + 2] + brightnessValue > 255)
            {
                imageData[pixel * 3 + 2] = 255;
            }
            else if (imageData[pixel * 3 + 2] + brightnessValue < 0)
            {
                imageData[pixel * 3 + 2] = 0;
            }
            else
            {
                imageData[pixel * 3 + 2] += brightnessValue;
            }
        }
    }
}

void rotate(unsigned char *imageData, int imageWidth, int imageHeight, float angle)
{
    int row, col, pixel;
    float radians = angle * M_PI / 180.0;
    unsigned char *tempData = (unsigned char *) malloc(sizeof(unsigned char) * imageWidth * imageHeight * 3);
    memcpy(tempData, imageData, sizeof(unsigned char) * imageWidth * imageHeight * 3);
    int newWidth = (int) (ceil(fabs((float) imageWidth * cos(radians))) + ceil(fabs((float) imageHeight * sin(radians))));
    int newHeight = (int) (ceil(fabs((float) imageHeight * cos(radians))) + ceil(fabs((float) imageWidth * sin(radians))));
    int xOffset = (int) ((newWidth - imageWidth) / 2);
    int yOffset = (int) ((newHeight - imageHeight) / 2);
    for (row = 0; row < newHeight; row++)
    {
        for (col = 0; col < newWidth; col++)
        {
            pixel = (row * newWidth + col) * 3;
            int x = (int) ((col - xOffset) * cos(radians) + (row - yOffset) * sin(radians));
            int y = (int) ((col - xOffset) * -sin(radians) + (row - yOffset) * cos(radians));
            if (x >= 0 && y >= 0 && x < imageWidth && y < imageHeight)
            {
                int oldPixel = (y * imageWidth + x) * 3;
                imageData[pixel + 0] = tempData[oldPixel + 0];
                imageData[pixel + 1] = tempData[oldPixel + 1];
                imageData[pixel + 2] = tempData[oldPixel + 2];
            }
        }
    }
    free(tempData);
}

void saveImage(char *filename, unsigned char *imageData, int imageWidth, int imageHeight)
{
    FILE *file;
    file = fopen(filename, "wb");
    if (file == NULL) return;
    fprintf(file, "P6\n%d %d\n255\n", imageWidth, imageHeight);
    fwrite(imageData, 1, imageWidth * imageHeight * 3, file);
    fclose(file);
}

int main()
{
    FILE *file;
    char filename[100];
    unsigned char *imageData;
    int imageWidth, imageHeight, maxColorVal, choice, brightnessValue, success, i, j;
    float angle;
    printf("Enter the file name of the image: ");
    scanf("%s", filename);
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    char version[3];
    success = fscanf(file, "%s", version);
    if (strcmp(version, "P6"))
    {
        printf("Invalid file format. Only P6 format supported.\n");
        fclose(file);
        return 1;
    }
    success = fscanf(file, "%d %d", &imageWidth, &imageHeight);
    success = fscanf(file, "%d", &maxColorVal);
    if (maxColorVal != 255)
    {
        printf("Invalid maximum color value. Only 255 supported.\n");
        fclose(file);
        return 1;
    }
    imageData = (unsigned char *) malloc(sizeof(unsigned char) * imageWidth * imageHeight * 3);
    fread(imageData, 1, imageWidth * imageHeight * 3, file);
    fclose(file);
    printf("Image loaded successfully.\n");
    choice = -1;
    while (choice != 0)
    {
        printf("\nMenu\n");
        printf("1. Convert to grayscale\n");
        printf("2. Invert colors\n");
        printf("3. Blur image\n");
        printf("4. Adjust brightness\n");
        printf("5. Rotate image\n");
        printf("6. Save image\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                grayscale(imageData, imageWidth, imageHeight);
                printf("Image converted to grayscale.\n");
                break;
            case 2:
                invert(imageData, imageWidth, imageHeight);
                printf("Colors inverted.\n");
                break;
            case 3:
                blur(imageData, imageWidth, imageHeight);
                printf("Image blurred.\n");
                break;
            case 4:
                printf("Enter the brightness value (-255 to 255): ");
                scanf("%d", &brightnessValue);
                brightness(imageData, imageWidth, imageHeight, brightnessValue);
                printf("Image brightness adjusted.\n");
                break;
            case 5:
                printf("Enter angle of rotation: ");
                scanf("%f", &angle);
                rotate(imageData, imageWidth, imageHeight, angle);
                printf("Image rotated.\n");
                break;
            case 6:
                printf("Enter the file name to save the image as: ");
                scanf("%s", filename);
                saveImage(filename, imageData, imageWidth, imageHeight);
                printf("Image saved.\n");
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    free(imageData);
    return 0;
}