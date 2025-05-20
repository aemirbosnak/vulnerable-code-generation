//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PIXELS 256
#define MAX_IMAGE_SIZE 1024

struct Image{
    int width, height;
    int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
};

typedef struct Image Image;

void print_menu();
void print_image(Image* img, int flip, float brightness, float contrast);
void flip_image(Image* img, int flip);
void adjust_brightness(Image* img, float brightness);
void adjust_contrast(Image* img, float contrast);

int main(){
    Image img;
    int menu_choice, flip_choice;
    float brightness, contrast;
    
    printf("Enter image width: ");
    scanf("%d", &img.width);
    
    printf("Enter image height: ");
    scanf("%d", &img.height);

    // Generate random pixel values within the range of 0-255
    for(int i=0; i<img.height; i++){
        for(int j=0; j<img.width; j++){
            img.pixels[i][j] = rand() % MAX_PIXELS;
        }
    }

    // Main program loop
    do{
        print_menu();
        scanf("%d", &menu_choice);

        switch(menu_choice){
            case 1: // Flip image
                printf("Choose a flip direction (1 - horizontal, 2 - vertical): ");
                scanf("%d", &flip_choice);
                flip_image(&img, flip_choice);
                break;

            case 2: // Adjust brightness
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%f", &brightness);
                adjust_brightness(&img, brightness);
                break;

            case 3: // Adjust contrast
                printf("Enter contrast adjustment (0.1 to 10.0): ");
                scanf("%f", &contrast);
                adjust_contrast(&img, contrast);
                break;

            case 4: // Quit program
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }

        print_image(&img, flip_choice, brightness, contrast);

    }while(menu_choice != 4);

    return 0;
}

void print_menu(){
    printf("\n-----------------------\n");
    printf("1. Flip image\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    printf("4. Quit\n");
    printf("-----------------------\n\n");
}

void print_image(Image* img, int flip, float brightness, float contrast){
    printf("********** IMAGE **********\n");
    printf("Width: %d px\n", img->width);
    printf("Height: %d px\n", img->height);
    printf("Flip direction: ");
    if(flip == 1){
        printf("horizontal\n");
    }
    else if(flip == 2){
        printf("vertical\n");
    }
    else{
        printf("none\n");
    }
    printf("Brightness adjustment: %f\n", brightness);
    printf("Contrast adjustment: %f\n", contrast);
    printf("Pixels:\n");

    // Print pixel values with spaces in between for readability
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void flip_image(Image* img, int flip){
    int temp_pixel;
    if(flip == 1){ // Horizontal flip
        for(int i=0; i<img->height; i++){
            for(int j=0; j<img->width/2; j++){
                // Swap pixels on opposite sides of the image
                temp_pixel = img->pixels[i][j];
                img->pixels[i][j] = img->pixels[i][img->width-j-1];
                img->pixels[i][img->width-j-1] = temp_pixel;
            }
        }
    }
    else if(flip == 2){ // Vertical flip
        for(int i=0; i<img->height/2; i++){
            for(int j=0; j<img->width; j++){
                // Swap pixels on opposite sides of the image
                temp_pixel = img->pixels[i][j];
                img->pixels[i][j] = img->pixels[img->height-i-1][j];
                img->pixels[img->height-i-1][j] = temp_pixel;
            }
        }
    }
}

void adjust_brightness(Image* img, float brightness){
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            img->pixels[i][j] += (int)brightness;
            // Clamp pixel values to the range of 0-255
            if(img->pixels[i][j] > 255){
                img->pixels[i][j] = 255;
            }
            else if(img->pixels[i][j] < 0){
                img->pixels[i][j] = 0;
            }
        }
    }
}

void adjust_contrast(Image* img, float contrast){
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            img->pixels[i][j] = (int)(factor * (img->pixels[i][j] - 128) + 128);
            // Clamp pixel values to the range of 0-255
            if(img->pixels[i][j] > 255){
                img->pixels[i][j] = 255;
            }
            else if(img->pixels[i][j] < 0){
                img->pixels[i][j] = 0;
            }
        }
    }
}