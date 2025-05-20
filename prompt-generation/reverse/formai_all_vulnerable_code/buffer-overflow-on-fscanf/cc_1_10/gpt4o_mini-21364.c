//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img, int horizontal);
void adjust_brightness_contrast(Image *img, int brightness, float contrast);
void free_image(Image *img);

int main() {
    char input_file[100], output_file[100];
    int choice, brightness;
    float contrast;
    
    printf("Enter the input PPM file name: ");
    scanf("%s", input_file);
    
    Image *img = load_image(input_file);
    if (img == NULL) {
        fprintf(stderr, "Error loading image.\n");
        return EXIT_FAILURE;
    }

    printf("Choose an action:\n");
    printf("1. Flip Image (Vertical)\n");
    printf("2. Flip Image (Horizontal)\n");
    printf("3. Adjust Brightness and Contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_image(img, 1);
            strcpy(output_file, "flipped_vertical.ppm");
            break;
        case 2:
            flip_image(img, 0);
            strcpy(output_file, "flipped_horizontal.ppm");
            break;
        case 3:
            printf("Enter brightness adjustment (-255 to 255): ");
            scanf("%d", &brightness);
            printf("Enter contrast adjustment (0.0 to 2.0): ");
            scanf("%f", &contrast);
            adjust_brightness_contrast(img, brightness, contrast);
            strcpy(output_file, "adjusted_brightness_contrast.ppm");
            break;
        default:
            fprintf(stderr, "Invalid choice!\n");
            free_image(img);
            return EXIT_FAILURE;
    }

    save_image(output_file, img);
    free_image(img);
    printf("Processed image saved as %s\n", output_file);
    return EXIT_SUCCESS;
}

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    if (!img) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P3") != 0) {
        fprintf(stderr, "Unsupported PPM format\n");
        free(img);
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    
    img->data = malloc(sizeof(Pixel) * img->width * img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &img->data[i].r, &img->data[i].g, &img->data[i].b);
    }

    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file to save");
        return;
    }

    fprintf(file, "P3\n%d %d\n255\n", img->width, img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(file, "%d %d %d\n", img->data[i].r, img->data[i].g, img->data[i].b);
    }

    fclose(file);
}

void flip_image(Image *img, int horizontal) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int swap_index = horizontal ? x : img->width - 1 - x;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + swap_index];
            img->data[y * img->width + swap_index] = temp;
        }
    }
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = fmin(255, fmax(0, (int)(img->data[i].r * contrast + brightness)));
        img->data[i].g = fmin(255, fmax(0, (int)(img->data[i].g * contrast + brightness)));
        img->data[i].b = fmin(255, fmax(0, (int)(img->data[i].b * contrast + brightness)));
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}