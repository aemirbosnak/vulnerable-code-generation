//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
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

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int value);
void adjust_contrast(Image *img, float factor);
void free_image(Image *img);

int main() {
    char filename[100];
    int choice;

    printf("Welcome to the image processing puzzle!\n");
    printf("Enter the image file name to load (e.g., image.ppm): ");
    scanf("%s", filename);

    Image *img = load_image(filename);
    if (img == NULL) {
        printf("Error loading image.\n");
        return 1;
    }

    do {
        printf("\nChoose an operation:\n");
        printf("1. Flip image\n");
        printf("2. Change brightness\n");
        printf("3. Adjust contrast\n");
        printf("4. Save image\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flip_image(img);
                printf("Image flipped!\n");
                break;
            case 2: {
                int value;
                printf("Enter brightness adjustment value (-255 to 255): ");
                scanf("%d", &value);
                adjust_brightness(img, value);
                printf("Brightness adjusted!\n");
                break;
            }
            case 3: {
                float factor;
                printf("Enter contrast adjustment factor (0.0 to 2.0): ");
                scanf("%f", &factor);
                adjust_contrast(img, factor);
                printf("Contrast adjusted!\n");
                break;
            }
            case 4: {
                char output_filename[100];
                printf("Enter the output image file name (e.g., output.ppm): ");
                scanf("%s", output_filename);
                save_image(output_filename, img);
                printf("Image saved!\n");
                break;
            }
            case 5:
                printf("Exiting...\n");
                free_image(img);
                return 0;
            default:
                printf("Invalid choice. Try again!\n");
        }
    } while (1);
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char buffer[16];
    fgets(buffer, sizeof(buffer), file);
    if (buffer[0] != 'P' || buffer[1] != '6') {
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    fgetc(file); // Consume the newline after the max color value

    img->data = (Pixel *)malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - x - 1;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + opposite_x];
            img->data[y * img->width + opposite_x] = temp;
        }
    }
}

void adjust_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char)fmax(0, fmin(255, img->data[i].r + value));
        img->data[i].g = (unsigned char)fmax(0, fmin(255, img->data[i].g + value));
        img->data[i].b = (unsigned char)fmax(0, fmin(255, img->data[i].b + value));
    }
}

void adjust_contrast(Image *img, float factor) {
    if (factor < 0) factor = 0;
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char)fmax(0, fmin(255, (int)(((img->data[i].r - 128) * factor) + 128)));
        img->data[i].g = (unsigned char)fmax(0, fmin(255, (int)(((img->data[i].g - 128) * factor) + 128)));
        img->data[i].b = (unsigned char)fmax(0, fmin(255, (int)(((img->data[i].b - 128) * factor) + 128)));
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}