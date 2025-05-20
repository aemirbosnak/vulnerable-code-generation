//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_PIXEL 255

void readImage(char* filename, int *img, int *rows, int *cols)
{
    FILE *fptr;
    int i, j;

    fptr = fopen(filename, "rb");

    if(fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    fscanf(fptr, "%d", cols);
    fscanf(fptr, "%d", rows);

    for(i = 0; i < *rows; i++)
    {
        for(j = 0; j < *cols; j++)
        {
            fscanf(fptr, "%d", &img[i * (*cols) + j]);
        }
    }

    fclose(fptr);
}

void writeImage(char* filename, int *img, int rows, int cols)
{
    FILE *fptr;
    int i, j;

    fptr = fopen(filename, "wb");

    if(fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    fprintf(fptr, "%d ", cols);
    fprintf(fptr, "%d\n", rows);

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            fprintf(fptr, "%d ", img[i * cols + j]);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}

void flipHorizontal(int *img, int rows, int cols)
{
    int i, j, temp;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols/2; j++)
        {
            temp = img[i * cols + j];
            img[i * cols + j] = img[i * cols + (cols-1-j)];
            img[i * cols + (cols-1-j)] = temp;
        }
    }
}

void flipVertical(int *img, int rows, int cols)
{
    int i, j, temp;

    for(i = 0; i < rows/2; i++)
    {
        for(j = 0; j < cols; j++)
        {
            temp = img[i * cols + j];
            img[i * cols + j] = img[(rows-1-i) * cols + j];
            img[(rows-1-i) * cols + j] = temp;
        }
    }
}

void adjustContrast(int *img, int rows, int cols, float contrast)
{
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    int i, j, val;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            val = (int)(factor * (img[i * cols + j] - 128) + 128);

            if(val > MAX_PIXEL)
            {
                img[i * cols + j] = MAX_PIXEL;
            }
            else if(val < 0)
            {
                img[i * cols + j] = 0;
            }
            else
            {
                img[i * cols + j] = val;
            }
        }
    }
}

void adjustBrightness(int *img, int rows, int cols, int brightness)
{
    int i, j, val;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            val = img[i * cols + j] + brightness;

            if(val > MAX_PIXEL)
            {
                img[i * cols + j] = MAX_PIXEL;
            }
            else if(val < 0)
            {
                img[i * cols + j] = 0;
            }
            else
            {
                img[i * cols + j] = val;
            }
        }
    }
}

int main()
{
    char filename[] = "input_image.txt";
    char outputFilename[] = "output_image.txt";
    int *img, rows, cols;

    img = (int*)malloc(rows * cols * sizeof(int));

    readImage(filename, img, &rows, &cols);

    printf("Image height: %d\n", rows);
    printf("Image width: %d\n", cols);

    flipHorizontal(img, rows, cols);

    printf("Image flipped horizontally.\n");

    adjustContrast(img, rows, cols, 50.0);

    printf("Contrast adjusted.\n");

    flipVertical(img, rows, cols);

    printf("Image flipped vertically.\n");

    adjustBrightness(img, rows, cols, -50);

    printf("Brightness adjusted.\n");

    writeImage(outputFilename, img, rows, cols);

    printf("Output image written to %s\n", outputFilename);

    free(img);

    return 0;
}