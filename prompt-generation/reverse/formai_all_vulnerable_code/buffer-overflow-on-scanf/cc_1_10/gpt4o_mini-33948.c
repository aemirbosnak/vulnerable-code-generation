//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t file_type;     
    uint32_t file_size;     
    uint16_t reserved1;     
    uint16_t reserved2;     
    uint32_t offset_data;   
} BMPHeader;

typedef struct {
    uint32_t size;        
    uint32_t width;       
    uint32_t height;      
    uint16_t planes;      
    uint16_t bit_count;   
    uint32_t compression;  
    uint32_t size_image;  
    uint32_t x_pels_per_meter;  
    uint32_t y_pels_per_meter;  
    uint32_t colors_used;  
    uint32_t important_colors; 
} BMPInfoHeader;

typedef struct {
    uint8_t blue;  
    uint8_t green; 
    uint8_t red;   
} RGB;
#pragma pack(pop)

void flip_image(RGB **image, int width, int height, int vertical);
void adjust_brightness_contrast(RGB **image, int width, int height, int brightness, float contrast);
void load_bmp(const char *filename, BMPHeader *bmp_header, BMPInfoHeader *bmp_info_header, RGB ***image, int *width, int *height);
void save_bmp(const char *filename, BMPHeader *bmp_header, BMPInfoHeader *bmp_info_header, RGB **image, int width, int height);
void free_image(RGB **image, int height);

int main() {
    const char *filename = "input.bmp";
    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;
    RGB **image;
    int width, height;

    load_bmp(filename, &bmp_header, &bmp_info_header, &image, &width, &height);

    int choice;
    printf("Select an operation:\n");
    printf("1. Flip Image\n");
    printf("2. Adjust Brightness/Contrast\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int direction;
        printf("Select direction (1: Horizontal, 2: Vertical): ");
        scanf("%d", &direction);
        flip_image(image, width, height, direction == 2);
    } else if (choice == 2) {
        int brightness;
        float contrast;
        printf("Enter brightness adjustment (-255 to 255): ");
        scanf("%d", &brightness);
        printf("Enter contrast adjustment (0.0 to 3.0): ");
        scanf("%f", &contrast);
        adjust_brightness_contrast(image, width, height, brightness, contrast);
    } else {
        printf("Invalid choice\n");
        free_image(image, height);
        return 1;
    }

    save_bmp("output.bmp", &bmp_header, &bmp_info_header, image, width, height);
    free_image(image, height);
    printf("Operation completed. Saved as output.bmp.\n");
    return 0;
}

void load_bmp(const char *filename, BMPHeader *bmp_header, BMPInfoHeader *bmp_info_header, RGB ***image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fread(bmp_header, sizeof(BMPHeader), 1, file);
    fread(bmp_info_header, sizeof(BMPInfoHeader), 1, file);

    *width = bmp_info_header->width;
    *height = bmp_info_header->height;

    *image = (RGB **)malloc((*height) * sizeof(RGB *));
    for (int i = 0; i < *height; i++) {
        (*image)[i] = (RGB *)malloc((*width) * sizeof(RGB));
        fseek(file, bmp_header->offset_data + (i * (*width) * sizeof(RGB)), SEEK_SET);
        fread((*image)[i], sizeof(RGB), *width, file);
    }

    fclose(file);
}

void save_bmp(const char *filename, BMPHeader *bmp_header, BMPInfoHeader *bmp_info_header, RGB **image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(bmp_header, sizeof(BMPHeader), 1, file);
    fwrite(bmp_info_header, sizeof(BMPInfoHeader), 1, file);

    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(RGB), width, file);
        free(image[i]);
    }
    fclose(file);
}

void flip_image(RGB **image, int width, int height, int vertical) {
    if (vertical) {
        for (int i = 0; i < height / 2; i++) {
            for (int j = 0; j < width; j++) {
                RGB temp = image[i][j];
                image[i][j] = image[height - 1 - i][j];
                image[height - 1 - i][j] = temp;
            }
        }
    } else {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width / 2; j++) {
                RGB temp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp;
            }
        }
    }
}

void adjust_brightness_contrast(RGB **image, int width, int height, int brightness, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int red = (int)(image[i][j].red * contrast + brightness);
            int green = (int)(image[i][j].green * contrast + brightness);
            int blue = (int)(image[i][j].blue * contrast + brightness);

            image[i][j].red = (red < 0) ? 0 : (red > 255) ? 255 : red;
            image[i][j].green = (green < 0) ? 0 : (green > 255) ? 255 : green;
            image[i][j].blue = (blue < 0) ? 0 : (blue > 255) ? 255 : blue;
        }
    }
}

void free_image(RGB **image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}