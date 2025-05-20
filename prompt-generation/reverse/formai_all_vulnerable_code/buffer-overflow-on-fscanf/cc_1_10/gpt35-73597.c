//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PIXELS 1000

/* function prototypes */
void read_image(char filename[], char pixels[][MAX_PIXELS], int *width, int *height);
void write_image(char filename[], char pixels[][MAX_PIXELS], int width, int height);
void flip_image(char pixels[][MAX_PIXELS], int width, int height);
void adjust_brightness(char pixels[][MAX_PIXELS], int width, int height, int brightness);
void adjust_contrast(char pixels[][MAX_PIXELS], int width, int height, int contrast);

/* main function */
int main()
{
    char filename[20];
    char pixels[MAX_PIXELS][MAX_PIXELS];
    int width = 0, height = 0;
    int choice, brightness, contrast;

    printf("Enter the filename of the image to process: ");
    scanf("%s", filename);

    read_image(filename, pixels, &width, &height);

    printf("\nThe image has been read successfully!\n\n");

    do {
        printf("What would you like to do?\n\n");
        printf("1. Flip the image\n");
        printf("2. Adjust brightness\n");
        printf("3. Adjust contrast\n");
        printf("4. Save the image and exit\n\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                flip_image(pixels, width, height);
                printf("\nThe image has been flipped successfully!\n\n");
                break;
            case 2:
                printf("\nEnter the brightness level (-128 to 127): ");
                scanf("%d", &brightness);
                adjust_brightness(pixels, width, height, brightness);
                printf("\nThe brightness has been adjusted successfully!\n\n");
                break;
            case 3:
                printf("\nEnter the contrast level (-128 to 127): ");
                scanf("%d", &contrast);
                adjust_contrast(pixels, width, height, contrast);
                printf("\nThe contrast has been adjusted successfully!\n\n");
                break;
            case 4:
                write_image(filename, pixels, width, height);
                printf("\nThe image has been saved successfully!\n\n");
                break;
            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

/* function to read an image from a file */
void read_image(char filename[], char pixels[][MAX_PIXELS], int *width, int *height)
{
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("\nError: Unable to open the file!\n");
        exit(1);
    }

    fscanf(fp, "%d %d", width, height);

    for(i=0; i<*height; i++) {
        for(j=0; j<*width; j++) {
            fscanf(fp, " %c", &pixels[i][j]);
        }
    }

    fclose(fp);
}

/* function to write an image to a file */
void write_image(char filename[], char pixels[][MAX_PIXELS], int width, int height)
{
    FILE *fp;
    int i, j;

    fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("\nError: Unable to create the file!\n");
        exit(1);
    }

    fprintf(fp, "%d %d\n", width, height);

    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            fprintf(fp, "%c ", pixels[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

/* function to flip an image horizontally */
void flip_image(char pixels[][MAX_PIXELS], int width, int height)
{
    int i, j;
    char temp;

    for(i=0; i<height; i++) {
        for(j=0; j<width/2; j++) {
            temp = pixels[i][j];
            pixels[i][j] = pixels[i][width-j-1];
            pixels[i][width-j-1] = temp;
        }
    }
}

/* function to adjust the brightness of an image */
void adjust_brightness(char pixels[][MAX_PIXELS], int width, int height, int brightness)
{
    int i, j;

    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            if(isdigit(pixels[i][j])) {
                pixels[i][j] += brightness;
            }
        }
    }
}

/* function to adjust the contrast of an image */
void adjust_contrast(char pixels[][MAX_PIXELS], int width, int height, int contrast)
{
    int i, j;

    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            if(isdigit(pixels[i][j])) {
                if((int)(pixels[i][j]) + contrast > 255) {
                    pixels[i][j] = 255;
                }
                else if((int)(pixels[i][j]) + contrast < 0) {
                    pixels[i][j] = 0;
                }
                else {
                    pixels[i][j] += contrast;
                }
            }
        }
    }
}