//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Image {
    int *pixels;
    int width;
    int height;
} Image;

void display_menu();
Image *load_image(char *filename);
void save_image(Image *image, char *filename);
void flip_image(Image *image);
void adjust_brightness(Image *image, int value);
void adjust_contrast(Image *image, float value);

int main() {
    int choice, value;
    char filename[100];
    float contrast_value;
    Image *image = NULL;
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the filename: ");
                scanf("%s", filename);
                image = load_image(filename);
                if(image != NULL) {
                    printf("\nImage loaded successfully!\n");
                }
                break;
                
            case 2:
                if(image != NULL) {
                    printf("\nEnter the filename: ");
                    scanf("%s", filename);
                    save_image(image, filename);
                    printf("\nImage saved successfully!\n");
                }
                else {
                    printf("\nPlease load an image first!\n");
                }
                break;
                
            case 3:
                if(image != NULL) {
                    flip_image(image);
                    printf("\nImage flipped successfully!\n");
                }
                else {
                    printf("\nPlease load an image first!\n");
                }
                break;
                
            case 4:
                if(image != NULL) {
                    printf("\nEnter the brightness value (-255 to 255): ");
                    scanf("%d", &value);
                    adjust_brightness(image, value);
                    printf("\nBrightness adjusted successfully!\n");
                }
                else {
                    printf("\nPlease load an image first!\n");
                }
                break;
                
            case 5:
                if(image != NULL) {
                    printf("\nEnter the contrast value (0.0 to 2.0): ");
                    scanf("%f", &contrast_value);
                    adjust_contrast(image, contrast_value);
                    printf("\nContrast adjusted successfully!\n");
                }
                else {
                    printf("\nPlease load an image first!\n");
                }
                break;
                
            case 6:
                printf("\nExiting...\n");
                if(image != NULL) {
                    free(image->pixels);
                    free(image);
                }
                exit(0);
                
            default:
                printf("\nInvalid choice!\n");
        }
    } while(1);
    
    return 0;
}

void display_menu() {
    printf("\nBasic Image Processing\n");
    printf("1. Load an image\n");
    printf("2. Save the image\n");
    printf("3. Flip the image\n");
    printf("4. Adjust brightness\n");
    printf("5. Adjust contrast\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

Image *load_image(char *filename) {
    FILE *file;
    char magic_number[3];
    int width, height, max_value;
    Image *image = NULL;
    
    file = fopen(filename, "r");
    if(file != NULL) {
        fscanf(file, "%s", magic_number);
        if(strcmp(magic_number, "P3") == 0) {
            fscanf(file, "%d %d %d", &width, &height, &max_value);
            image = malloc(sizeof(Image));
            image->width = width;
            image->height = height;
            image->pixels = malloc(width * height * sizeof(int));
            for(int i = 0; i < width * height; i++) {
                int red, green, blue;
                fscanf(file, "%d %d %d", &red, &green, &blue);
                image->pixels[i] = (red << 16) | (green << 8) | blue;
            }
            fclose(file);
        }
        else {
            printf("\nUnsupported file format!\n");
        }
    }
    else {
        printf("\nFailed to open the file!\n");
    }
    
    return image;
}

void save_image(Image *image, char *filename) {
    FILE *file;
    
    file = fopen(filename, "w");
    if(file != NULL) {
        fprintf(file, "P3\n");
        fprintf(file, "%d %d\n", image->width, image->height);
        fprintf(file, "255\n");
        for(int i = 0; i < image->width * image->height; i++) {
            int red = (image->pixels[i] >> 16) & 0xFF;
            int green = (image->pixels[i] >> 8) & 0xFF;
            int blue = image->pixels[i] & 0xFF;
            fprintf(file, "%d %d %d\n", red, green, blue);
        }
        fclose(file);
    }
    else {
        printf("\nFailed to create the file!\n");
    }
}

void flip_image(Image *image) {
    int temp;
    
    for(int i = 0; i < image->height / 2; i++) {
        for(int j = 0; j < image->width; j++) {
            temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[(image->height - 1 - i) * image->width + j];
            image->pixels[(image->height - 1 - i) * image->width + j] = temp;
        }
    }
}

void adjust_brightness(Image *image, int value) {
    for(int i = 0; i < image->width * image->height; i++) {
        int red = (image->pixels[i] >> 16) & 0xFF;
        int green = (image->pixels[i] >> 8) & 0xFF;
        int blue = image->pixels[i] & 0xFF;
        red += value;
        green += value;
        blue += value;
        red = red < 0 ? 0 : red > 255 ? 255 : red;
        green = green < 0 ? 0 : green > 255 ? 255 : green;
        blue = blue < 0 ? 0 : blue > 255 ? 255 : blue;
        image->pixels[i] = (red << 16) | (green << 8) | blue;
    }
}

void adjust_contrast(Image *image, float value) {
    float factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    
    for(int i = 0; i < image->width * image->height; i++) {
        int red = (image->pixels[i] >> 16) & 0xFF;
        int green = (image->pixels[i] >> 8) & 0xFF;
        int blue = image->pixels[i] & 0xFF;
        red = factor * (red - 128) + 128;
        green = factor * (green - 128) + 128;
        blue = factor * (blue - 128) + 128;
        red = red < 0 ? 0 : red > 255 ? 255 : red;
        green = green < 0 ? 0 : green > 255 ? 255 : green;
        blue = blue < 0 ? 0 : blue > 255 ? 255 : blue;
        image->pixels[i] = (red << 16) | (green << 8) | blue;
    }
}