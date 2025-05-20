//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 500
#define WIDTH 500

// Function to load image from file into a 2D array
void load_image(char file_name[], int image[HEIGHT][WIDTH]) {
    FILE* fp;
    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);
}

// Function to save image from 2D array to file
void save_image(char file_name[], int image[HEIGHT][WIDTH]) {
    FILE* fp;
    fp = fopen(file_name, "w");
    if(fp == NULL) {
        printf("Error: Unable to save file\n");
        exit(1);
    }
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Function to flip the image horizontally
void flip_image_h(int image[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH-j-1];
            image[i][WIDTH-j-1] = temp;
        }
    }
}

// Function to flip the image vertically
void flip_image_v(int image[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT/2; i++) {
        for(int j=0; j<WIDTH; j++) {
            int temp = image[i][j];
            image[i][j] = image[HEIGHT-i-1][j];
            image[HEIGHT-i-1][j] = temp;
        }
    }
}

// Function to increase the brightness of the image
void increase_brightness(int image[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            image[i][j] += 50;
            if(image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

// Function to decrease the brightness of the image
void decrease_brightness(int image[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            image[i][j] -= 50;
            if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Function to increase the contrast of the image
void increase_contrast(int image[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(image[i][j] < 128) {
                image[i][j] -= 50;
            } else {
                image[i][j] += 50;
            }
            if(image[i][j] > 255) {
                image[i][j] = 255;
            } else if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Function to decrease the contrast of the image
void decrease_contrast(int image[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(image[i][j] < 128) {
                image[i][j] += 50;
            } else {
                image[i][j] -= 50;
            }
            if(image[i][j] > 255) {
                image[i][j] = 255;
            } else if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

int main() {
    int image[HEIGHT][WIDTH];
    char file_name[50];

    // Load image from file
    printf("Enter file name to load image from: ");
    scanf("%s", file_name);
    load_image(file_name, image);

    // Apply image processing operations
    char choice;
    bool loop = true;
    while(loop) {
        printf("\nImage Processing Operators:\n");
        printf("1. Flip Horizontally\n");
        printf("2. Flip Vertically\n");
        printf("\nBrightness and Contrast:\n");
        printf("3. Increase Brightness\n");
        printf("4. Decrease Brightness\n");
        printf("5. Increase Contrast\n");
        printf("6. Decrease Contrast\n");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                flip_image_h(image);
                printf("Image flipped horizontally\n");
                break;
            case '2':
                flip_image_v(image);
                printf("Image flipped vertically\n");
                break;
            case '3':
                increase_brightness(image);
                printf("Brightness increased\n");
                break;
            case '4':
                decrease_brightness(image);
                printf("Brightness decreased\n");
                break;
            case '5':
                increase_contrast(image);
                printf("Contrast increased\n");
                break;
            case '6':
                decrease_contrast(image);
                printf("Contrast decreased\n");
                break;
            default:
                loop = false;
                printf("Exiting Image Processing Operators\n");
                break;
        }
    }

    // Save image to file
    printf("\nEnter file name to save image to: ");
    scanf("%s", file_name);
    save_image(file_name, image);

    return 0;
}