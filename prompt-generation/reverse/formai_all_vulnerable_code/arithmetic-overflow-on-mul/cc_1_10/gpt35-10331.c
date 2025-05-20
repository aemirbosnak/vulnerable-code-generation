//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_CHECK(ptr) if(ptr == NULL) { fprintf(stderr, "Memory allocation failed. Exiting."); exit(1); }

typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

Image* create_image(int width, int height) {
    Image* image = (Image*)malloc(sizeof(Image));
    MALLOC_CHECK(image);

    image->width = width;
    image->height = height;

    image->pixels = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    MALLOC_CHECK(image->pixels);

    return image;
}

void destroy_image(Image* image) {
    if(image) {
        if(image->pixels) {
            free(image->pixels);
        }
        free(image);
    }
}

void set_pixel(Image* image, int x, int y, unsigned char value) {
    if(x >= 0 && x < image->width && y >= 0 && y < image->height) {
        *(image->pixels + (y * image->width) + x) = value;
    }
}

unsigned char get_pixel(Image* image, int x, int y) {
    if(x >= 0 && x < image->width && y >= 0 && y < image->height) {
        return *(image->pixels + (y * image->width) + x);
    }
    return 0;
}

Image* read_image_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", filename);
        return NULL;
    }

    char signature[3];
    fread(signature, sizeof(char), 2, file);
    if(strcmp(signature, "P5") != 0) {
        fprintf(stderr, "File '%s' does not contain a grayscale PGM image.\n", filename);
        fclose(file);
        return NULL;
    }

    int width, height, max_value;
    fscanf(file, "%d %d %d\n", &width, &height, &max_value);

    if(max_value != 255) {
        fprintf(stderr, "Error: maximum pixel value is not 255 (not supported).\n");
        fclose(file);
        return NULL;
    }

    Image* image = create_image(width, height);

    fread(image->pixels, sizeof(unsigned char), width * height, file);

    fclose(file);

    return image;
}

void write_image_to_file(Image* image, char* filename) {
    FILE* file = fopen(filename, "w");
    if(file == NULL) {
        fprintf(stderr, "Error creating file '%s'.\n", filename);
        return;
    }

    fprintf(file, "P5\n%d %d\n%d\n", image->width, image->height, 255);

    fwrite(image->pixels, sizeof(unsigned char), image->width * image->height, file);

    fclose(file);
}

void apply_filter(Image* image, int filter_size, float* filter) {
    int half_filter_size = filter_size / 2;

    Image* temp_image = create_image(image->width, image->height);

    for(int y = 0; y < image->height; y++) {
        for(int x = 0; x < image->width; x++) {
            float sum = 0.0f;
            for(int filter_y = -half_filter_size; filter_y <= half_filter_size; filter_y++) {
                for(int filter_x = -half_filter_size; filter_x <= half_filter_size; filter_x++) {
                    int image_x = x + filter_x;
                    int image_y = y + filter_y;
                    float value = 0.0f;
                    if(image_x >= 0 && image_x < image->width && image_y >= 0 && image_y < image->height) {
                        value = (float)get_pixel(image, image_x, image_y);
                    }
                    float filter_value = *(filter + ((filter_y + half_filter_size) * filter_size) + (filter_x + half_filter_size));
                    sum += value * filter_value;
                }
            }
            unsigned char new_value = (unsigned char)sum;
            set_pixel(temp_image, x, y, new_value);
        }
    }

    memcpy(image->pixels, temp_image->pixels, image->width * image->height * sizeof(unsigned char));
    destroy_image(temp_image);
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    Image* image = read_image_from_file(argv[1]);
    if(image == NULL) {
        return 1;
    }

    float filter[9] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
    apply_filter(image, 3, filter);

    char output_filename[100];
    sprintf(output_filename, "filtered_%s", argv[1]);
    write_image_to_file(image, output_filename);

    destroy_image(image);

    return 0;
}