//FormAI DATASET v1.0 Category: Image Editor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//function to display menu
void display_menu() {
    printf("\n==C Image Editor==\n");
    printf("1. Add border to image\n");
    printf("2. Convert to grayscale\n");
    printf("3. Increase brightness\n");
    printf("4. Flip image horizontally\n");
    printf("5. Rotate image 90 degrees clockwise\n");
    printf("6. Invert colors\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

//function to get image dimensions from user
void get_image_dimensions(int *width, int *height) {
    printf("\nEnter image dimensions (width height): ");
    scanf("%d %d", width, height);
}

//function to get image data from user
void get_image_data(unsigned char *data, int width, int height) {
    printf("\nEnter image data in RGB format (0-255):\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = (i*width + j)*3;
            printf("Pixel (%d, %d): ", j, i);
            scanf("%hhu %hhu %hhu", &data[index], &data[index+1], &data[index+2]);    //using hhu format specifier to read unsigned char values
        }
    }
}

//function to add border to image
void add_border(unsigned char *data, int width, int height, int border_width, unsigned char *border_color) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(i<border_width || j<border_width || i>=height-border_width || j>=width-border_width) {
                int index = (i*width + j)*3;
                data[index] = border_color[0];
                data[index+1] = border_color[1];
                data[index+2] = border_color[2];
            }
        }
    }
}

//function to convert image to grayscale
void convert_to_grayscale(unsigned char *data, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = (i*width + j)*3;
            unsigned char r = data[index];
            unsigned char g = data[index+1];
            unsigned char b = data[index+2];
            unsigned char gray = (r + g + b)/3;
            data[index] = gray;
            data[index+1] = gray;
            data[index+2] = gray;
        }
    }
}

//function to increase brightness of image
void increase_brightness(unsigned char *data, int width, int height, int brightness) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = (i*width + j)*3;
            int r = data[index] + brightness;
            int g = data[index+1] + brightness;
            int b = data[index+2] + brightness;
            //limiting the values between 0 and 255
            data[index] = r<0 ? 0 : r>255 ? 255 : r;
            data[index+1] = g<0 ? 0 : g>255 ? 255 : g;
            data[index+2] = b<0 ? 0 : b>255 ? 255 : b;
        }
    }
}

//function to flip image horizontally
void flip_horizontally(unsigned char *data, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width/2; j++) {
            int index1 = (i*width + j)*3;
            int index2 = (i*width + (width-1-j))*3;
            //swapping the colors of the two pixels
            unsigned char temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
            temp = data[index1+1];
            data[index1+1] = data[index2+1];
            data[index2+1] = temp;
            temp = data[index1+2];
            data[index1+2] = data[index2+2];
            data[index2+2] = temp;
        }
    }
}

//function to rotate image 90 degrees clockwise
void rotate_90_clockwise(unsigned char *data, int *width, int *height) {
    //transposing the image
    unsigned char *temp = malloc((*width)*(*height)*3*sizeof(unsigned char));
    for(int i=0; i<(*height); i++) {
        for(int j=0; j<(*width); j++) {
            int index1 = (i*(*width) + j)*3;
            int index2 = (j*(*height) + i)*3;
            temp[index2] = data[index1];
            temp[index2+1] = data[index1+1];
            temp[index2+2] = data[index1+2];
        }
    }
    //flipping the transposed image horizontally
    flip_horizontally(temp, *height, *width);
    //updating the new width and height
    int temp_width = *width;
    *width = *height;
    *height = temp_width;
    //copying the rotated image back to the original array
    for(int i=0; i<(*height); i++) {
        for(int j=0; j<(*width); j++) {
            int index1 = (i*(*width) + j)*3;
            int index2 = (i*temp_width + j)*3;
            data[index1] = temp[index2];
            data[index1+1] = temp[index2+1];
            data[index1+2] = temp[index2+2];
        }
    }
    free(temp);
}

//function to invert colors of image
void invert_colors(unsigned char *data, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = (i*width + j)*3;
            data[index] = 255 - data[index];
            data[index+1] = 255 - data[index+1];
            data[index+2] = 255 - data[index+2];
        }
    }
}

int main() {
    int width, height, choice, border_width, brightness;
    unsigned char *data, *border_color;
    bool finished = false;

    get_image_dimensions(&width, &height);
    data = malloc(width*height*3*sizeof(unsigned char));
    get_image_data(data, width, height);

    while(!finished) {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("\nEnter border width: ");
                scanf("%d", &border_width);
                border_color = malloc(3*sizeof(unsigned char));
                printf("Enter border color in RGB format (0-255): ");
                scanf("%hhu %hhu %hhu", &border_color[0], &border_color[1], &border_color[2]);
                add_border(data, width, height, border_width, border_color);
                free(border_color);
                printf("\nBorder added successfully!\n");
                break;
            }
            case 2: {
                convert_to_grayscale(data, width, height);
                printf("\nConverted to grayscale successfully!\n");
                break;
            }
            case 3: {
                printf("\nEnter brightness value (+/- 255): ");
                scanf("%d", &brightness);
                increase_brightness(data, width, height, brightness);
                printf("\nBrightness increased successfully!\n");
                break;
            }
            case 4: {
                flip_horizontally(data, width, height);
                printf("\nFlipped horizontally successfully!\n");
                break;
            }
            case 5: {
                rotate_90_clockwise(data, &width, &height);
                printf("\nRotated 90 degrees clockwise successfully!\n");
                break;
            }
            case 6: {
                invert_colors(data, width, height);
                printf("\nColors inverted successfully!\n");
                break;
            }
            case 7: {
                finished = true;
                printf("\nExiting program...\n");
                break;
            }
            default: {
                printf("\nInvalid choice! Please try again.\n");
                break;
            }
        }
    }

    free(data);
    return 0;
}