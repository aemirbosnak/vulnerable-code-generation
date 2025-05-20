//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void apply_grayscale(Image *img);
void invert_colors(Image *img);
void free_image(Image *img);

int main() {
    char input_file[100], output_file[100];
    int choice;
    Image *image = NULL;

    printf("Enter the input PPM file name: ");
    scanf("%s", input_file);
    
    image = load_ppm(input_file);
    if (image == NULL) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    printf("Choose an action:\n");
    printf("1. Convert to Grayscale\n");
    printf("2. Invert Colors\n");
    printf("3. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            apply_grayscale(image);
            sprintf(output_file, "grayscale_%s", input_file);
            save_ppm(output_file, image);
            printf("Grayscale image saved as %s\n", output_file);
            break;
        case 2:
            invert_colors(image);
            sprintf(output_file, "inverted_%s", input_file);
            save_ppm(output_file, image);
            printf("Inverted image saved as %s\n", output_file);
            break;
        case 3:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    free_image(image);
    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    
    char buffer[16];
    fgets(buffer, sizeof(buffer), file);
    if (strcmp(buffer, "P6\n") != 0) {
        fprintf(stderr, "Not a binary PPM file.\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &(img->width), &(img->height));
    int max_color;
    fscanf(file, "%d", &max_color);
    fgetc(file);  // Read the newline after max color

    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void apply_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        unsigned char gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}