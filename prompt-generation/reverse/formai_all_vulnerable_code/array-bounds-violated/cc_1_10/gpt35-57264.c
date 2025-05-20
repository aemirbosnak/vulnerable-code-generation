//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILENAME_LENGTH 100
#define MAX_IMAGE_SIZE 1000000

// function to flip the image vertically
void flip_vertically(int *image, int width, int height) {
    int i, j;
    int temp;
    
    for (i = 0; i < height/2; i++) {
        for (j = 0; j < width; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + (height-1-i)*width + j);
            *(image + (height-1-i)*width + j) = temp;
        }
    }
}

// function to flip the image horizontally
void flip_horizontally(int *image, int width, int height) {
    int i, j;
    int temp;
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width/2; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + i*width + (width-1-j));
            *(image + i*width + (width-1-j)) = temp;
        }
    }
}

// function to change the brightness of the image
void change_brightness(int *image, int width, int height, int level) {
    int i, j;
    int temp;
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = *(image + i*width + j) + level;
            if (temp < 0) {
                *(image + i*width + j) = 0;
            }
            else if (temp > 255) {
                *(image + i*width + j) = 255;
            }
            else {
                *(image + i*width + j) = temp;
            }
        }
    }
}

// function to change the contrast of the image
void change_contrast(int *image, int width, int height, float factor) {
    int i, j;
    int temp;
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = (int)(factor * (*(image + i*width + j) - 128) + 128);
            if (temp < 0) {
                *(image + i*width + j) = 0;
            }
            else if (temp > 255) {
                *(image + i*width + j) = 255;
            }
            else {
                *(image + i*width + j) = temp;
            }
        }
    }
}

// function to read the image file
int read_image_file(char *filename, int *image, int *width, int *height) {
    FILE *f;
    int i, temp;
    int total_pixels;

    f = fopen(filename, "r");
    if (!f) {
        printf("Error opening image file %s\n", filename);
        return 0;
    }

    // read the width and height of the image
    fscanf(f, "%d\t%d\n", width, height);

    // calculate the total number of pixels
    total_pixels = (*width) * (*height);

    // read the pixel values of the image
    for (i = 0; i < total_pixels; i++) {
        fscanf(f, "%d", &temp);
        *(image + i) = temp;
    }

    fclose(f);

    return 1;
}

// function to write the image file
int write_image_file(char *filename, int *image, int width, int height) {
    FILE *f;
    int i;

    f = fopen(filename, "w");
    if (!f) {
        printf("Error creating image file %s\n", filename);
        return 0;
    }

    // write the width and height of the image
    fprintf(f, "%d\t%d\n", width, height);

    // write the pixel values of the image
    for (i = 0; i < width*height; i++) {
        fprintf(f, "%d ", *(image + i));
        if ((i+1) % width == 0) {
            fprintf(f, "\n");
        }
    }

    fclose(f);

    return 1;
}

int main() {
    int *image;
    char in_filename[MAX_PATH_LENGTH], out_filename[MAX_PATH_LENGTH];
    int width, height;
    char choice;
    int level;
    float factor;

    printf("Enter the input image file name: ");
    fgets(in_filename, sizeof(in_filename), stdin);

    // remove the newline character from the filename
    in_filename[strlen(in_filename)-1] = '\0';

    printf("Enter the output image file name: ");
    fgets(out_filename, sizeof(out_filename), stdin);

    // remove the newline character from the filename
    out_filename[strlen(out_filename)-1] = '\0';

    // allocate memory for the image
    image = (int *)malloc(MAX_IMAGE_SIZE * sizeof(int));
    if (!image) {
        printf("Memory allocation error\n");
        return 0;
    }

    // read the input image file
    if (!read_image_file(in_filename, image, &width, &height)) {
        return 0;
    }

    // ask the user for the operation to be performed
    printf("Choose the operation to be performed:\n");
    printf("1. Flip the image vertically\n");
    printf("2. Flip the image horizontally\n");
    printf("3. Change the brightness of the image\n");
    printf("4. Change the contrast of the image\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            flip_vertically(image, width, height);
            printf("Image flipped vertically\n");
            break;
        case '2':
            flip_horizontally(image, width, height);
            printf("Image flipped horizontally\n");
            break;
        case '3':
            printf("Enter the brightness level (between -255 and 255): ");
            scanf("%d", &level);
            change_brightness(image, width, height, level);
            printf("Brightness changed\n");
            break;
        case '4':
            printf("Enter the contrast factor (between 0.1 and 10.0): ");
            scanf("%f", &factor);
            change_contrast(image, width, height, factor);
            printf("Contrast changed\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    // write the output image file
    if (!write_image_file(out_filename, image, width, height)) {
        return 0;
    }

    free(image);

    return 0;
}