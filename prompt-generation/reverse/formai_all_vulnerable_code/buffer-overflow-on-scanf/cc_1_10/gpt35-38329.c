//FormAI DATASET v1.0 Category: Image Editor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILENAME_SIZE 256
#define MAX_PIXEL_SIZE 255

typedef struct Image {
    char filename[MAX_FILENAME_SIZE];
    int width;
    int height;
    int** pixels;
} Image;

void print_menu() {
    printf("------------------------------\n");
    printf(" MENU:                        \n");
    printf("------------------------------\n");
    printf(" 1. Load image                \n");
    printf(" 2. Save image                \n");
    printf(" 3. Display image             \n");
    printf(" 4. Invert image              \n");
    printf(" 5. Flip image horizontally   \n");
    printf(" 6. Rotate image 90 degrees   \n");
    printf(" 7. Exit                      \n");
    printf("------------------------------\n");
}

Image* load_image(char* filename) {
    Image* image = (Image*)malloc(sizeof(Image));
    strcpy(image->filename, filename);
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Could not open file for reading.\n");
        return NULL;
    }
    fscanf(fp, "%d %d", &image->width, &image->height);
    image->pixels = (int**)malloc(sizeof(int*) * image->height);
    for(int i = 0; i < image->height; i++) {
        image->pixels[i] = (int*)malloc(sizeof(int) * image->width);
        for(int j = 0; j < image->width; j++) {
            fscanf(fp, "%d", &image->pixels[i][j]);
        }
    }
    fclose(fp);
    printf("Image loaded successfully.\n");
    return image;
}

void save_image(Image* image) {
    FILE* fp = fopen(image->filename, "w");
    if(fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    fprintf(fp, "%d %d\n", image->width, image->height);
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            fprintf(fp, "%d ", image->pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Image saved successfully.\n");
}

void display_image(Image* image) {
    printf("Filename: %s\n", image->filename);
    printf("Dimensions: %dx%d\n", image->width, image->height);
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            printf("%3d ", image->pixels[i][j]);
        }
        printf("\n");
    }
}

void invert_image(Image* image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            image->pixels[i][j] = MAX_PIXEL_SIZE - image->pixels[i][j];
        }
    }
    printf("Image inverted successfully.\n");
}

void flip_image_horizontal(Image* image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width/2; j++) {
            int temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->width - j - 1];
            image->pixels[i][image->width - j - 1] = temp;
        }
    }
    printf("Image flipped horizontally successfully.\n");
}

void rotate_image_90_degrees(Image* image) {
    int new_width = image->height;
    int new_height = image->width;
    int** new_pixels = (int**)malloc(sizeof(int*) * new_height);
    for(int i = 0; i < new_height; i++) {
        new_pixels[i] = (int*)malloc(sizeof(int) * new_width);
    }
    for(int i = 0; i < new_height; i++) {
        for(int j = 0; j < new_width; j++) {
            new_pixels[i][j] = image->pixels[image->height - j - 1][i];
        }
    }
    for(int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    image->width = new_width;
    image->height = new_height;
    image->pixels = new_pixels;
    printf("Image rotated 90 degrees successfully.\n");
}

int main() {
    int choice;
    Image* image = NULL;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(image != NULL) {
                    printf("Warning: An image is already loaded. Do you want to overwrite it? (y/n) ");
                    char c;
                    scanf(" %c", &c);
                    if(c == 'n') {
                        break;
                    }
                }
                printf("Enter filename: ");
                char filename[MAX_FILENAME_SIZE];
                scanf("%s", filename);
                image = load_image(filename);
                break;
            case 2:
                if(image == NULL) {
                    printf("Error: No image is loaded.\n");
                    break;
                }
                save_image(image);
                break;
            case 3:
                if(image == NULL) {
                    printf("Error: No image is loaded.\n");
                    break;
                }
                display_image(image);
                break;
            case 4:
                if(image == NULL) {
                    printf("Error: No image is loaded.\n");
                    break;
                }
                invert_image(image);
                break;
            case 5:
                if(image == NULL) {
                    printf("Error: No image is loaded.\n");
                    break;
                }
                flip_image_horizontal(image);
                break;
            case 6:
                if(image == NULL) {
                    printf("Error: No image is loaded.\n");
                    break;
                }
                rotate_image_90_degrees(image);
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 7);
    return 0;
}