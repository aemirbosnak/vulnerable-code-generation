//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img);
void rotate_image(Image *img);
void adjust_brightness(Image *img, int adjustment);
void free_image(Image *img);
void display_menu();

int main() {
    char filename[100];
    
    printf("Welcome to the Magical C Image Editor!\n");
    printf("Please enter the filename of your PGM image (include '.pgm' extension): ");
    scanf("%s", filename);
    
    Image *img = load_image(filename);
    if (img == NULL) {
        fprintf(stderr, "Failed to load image. Exiting.\n");
        return 1;
    }
    
    int choice, brightness;
    do {
        display_menu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                flip_image(img);
                printf("Image flipped!\n");
                break;
            case 2:
                rotate_image(img);
                printf("Image rotated!\n");
                break;
            case 3:
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%d", &brightness);
                adjust_brightness(img, brightness);
                printf("Brightness adjusted!\n");
                break;
            case 4:
                save_image("edited_image.pgm", img);
                printf("Image saved as 'edited_image.pgm'!\n");
                break;
            case 0:
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    free_image(img);
    printf("Thank you for using the Magical C Image Editor! Goodbye!\n");
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P5") != 0) {
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    
    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P5\n%d %d\n%d\n", img->width, img->height, MAX_COLOR_VALUE);
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    unsigned char *flipped_data = (unsigned char *)malloc(img->width * img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            flipped_data[y * img->width + (img->width - 1 - x)] = img->data[y * img->width + x];
        }
    }
    free(img->data);
    img->data = flipped_data;
}

void rotate_image(Image *img) {
    unsigned char *rotated_data = (unsigned char *)malloc(img->width * img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            rotated_data[(img->width - 1 - x) * img->height + y] = img->data[y * img->width + x];
        }
    }
    free(img->data);
    img->data = rotated_data;
    // Swap width and height
    int temp = img->width;
    img->width = img->height;
    img->height = temp;
}

void adjust_brightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; i++) {
        int new_val = img->data[i] + adjustment;
        img->data[i] = (new_val < 0) ? 0 : (new_val > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : new_val;
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void display_menu() {
    printf("\n=== Magical Image Editor Menu ===\n");
    printf("1. Flip Image\n");
    printf("2. Rotate Image\n");
    printf("3. Adjust Brightness\n");
    printf("4. Save Image\n");
    printf("0. Exit\n");
}