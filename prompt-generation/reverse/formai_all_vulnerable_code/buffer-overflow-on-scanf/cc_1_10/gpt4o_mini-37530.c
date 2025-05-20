//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    unsigned int width, height;
    Pixel *pixels;
} Image;

void read_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        printf("Unsupported format: %s. Only P6 PPM is supported.\n", format);
        fclose(file);
        exit(1);
    }
    
    fscanf(file, "%u %u\n255\n", &img->width, &img->height);
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void write_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    fprintf(file, "P6\n%u %u\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void invert_colors(Image *img) {
    for (unsigned int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = 255 - img->pixels[i].r;
        img->pixels[i].g = 255 - img->pixels[i].g;
        img->pixels[i].b = 255 - img->pixels[i].b;
    }
}

void convert_to_grayscale(Image *img) {
    for (unsigned int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->pixels[i].r + img->pixels[i].g + img->pixels[i].b) / 3;
        img->pixels[i].r = gray;
        img->pixels[i].g = gray;
        img->pixels[i].b = gray;
    }
}

void free_image(Image *img) {
    free(img->pixels);
}

void show_menu() {
    printf("Welcome to the Peaceful Image Editor\n");
    printf("1. Invert colors\n");
    printf("2. Convert to grayscale\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    Image img;
    char input_filename[100], output_filename[100];
    
    printf("Enter the input PPM filename: ");
    scanf("%s", input_filename);
    
    read_ppm(input_filename, &img);
    
    while (1) {
        show_menu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                invert_colors(&img);
                printf("Colors inverted. Ready to save. \n");
                break;
            case 2:
                convert_to_grayscale(&img);
                printf("Converted to grayscale. Ready to save. \n");
                break;
            case 3:
                free_image(&img);
                printf("Exiting peacefully. Have a lovely day!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }
        
        printf("Enter the output filename: ");
        scanf("%s", output_filename);
        write_ppm(output_filename, &img);
        printf("Image saved successfully to %s\n", output_filename);
    }

    free_image(&img);
    return 0;
}