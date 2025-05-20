//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

/* Function to flip an image horizontally */
void flipHorizontally(int **image, int width, int height)
{
    int i, j, temp;
    for(i=0; i<height; i++){
        for(j=0; j<width/2; j++){
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

/* Function to adjust brightness of an image */
void changeBrightness(int **image, int width, int height, int brightness)
{
    int i, j;
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            image[i][j] += brightness;
            if(image[i][j] < 0) image[i][j] = 0;
            if(image[i][j] > 255) image[i][j] = 255;
        }
    }
}

/* Function to adjust contrast of an image */
void changeContrast(int **image, int width, int height, float contrast)
{
    int i, j;
    float factor = (259*(contrast+255)) / (255*(259-contrast));
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            image[i][j] = (int)(factor * (image[i][j] - 128) + 128);
        }
    }
}

int main()
{
    FILE *file;
    int **image, width, height, maxval, i, j, brightness;
    float contrast;

    /* Open PGM image file */
    file = fopen("image.pgm", "r");
    if(file == NULL){
        printf("Unable to open file\n");
        return 0;
    }

    /* Read header */
    fscanf(file, "P2\n%d %d\n%d\n", &width, &height, &maxval);

    /* Allocate memory for image */
    image = (int **)malloc(height * sizeof(int *));
    for(i=0; i<height; i++){
        image[i] = (int *)malloc(width * sizeof(int));
    }

    /* Read image data */
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            fscanf(file, "%d", &image[i][j]);
        }
    }

    /* Close file */
    fclose(file);

    /* Flip image horizontally */
    flipHorizontally(image, width, height);

    /* Adjust brightness of image */
    printf("Enter brightness value (-255 to 255): ");
    scanf("%d", &brightness);
    changeBrightness(image, width, height, brightness);

    /* Adjust contrast of image */
    printf("Enter contrast value (0 to 255): ");
    scanf("%f", &contrast);
    changeContrast(image, width, height, contrast);

    /* Save output image */
    file = fopen("output.pgm", "w");
    if(file == NULL){
        printf("Unable to create file\n");
        return 0;
    }

    /* Write header */
    fprintf(file, "P2\n%d %d\n%d\n", width, height, maxval);

    /* Write image data */
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }

    /* Close file */
    fclose(file);

    /* Free memory */
    for(i=0; i<height; i++){
        free(image[i]);
    }
    free(image);

    return 0;
}