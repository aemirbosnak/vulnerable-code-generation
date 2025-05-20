//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complex
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

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    // Read the header
    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    // Allocate memory for the data
    image->data = malloc(image->width * image->height * sizeof(Pixel));
    if (image->data == NULL) {
        perror("malloc");
        fclose(file);
        free(image);
        return NULL;
    }

    // Read the data
    fread(image->data, sizeof(Pixel), image->width * image->height, file);

    fclose(file);

    return image;
}

void write_image(const char *filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    // Write the header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the data
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

unsigned char get_bit(unsigned char byte, int bit) {
    return (byte >> bit) & 1;
}

void set_bit(unsigned char *byte, int bit, unsigned char value) {
    *byte = (*byte & ~(1 << bit)) | (value << bit);
}

void hide_data(Image *image, const char *data) {
    int data_length = strlen(data);
    int bit_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        Pixel *pixel = &image->data[i];

        for (int j = 0; j < 3; j++) {
            if (bit_index >= data_length * 8) {
                return;
            }

            unsigned char bit = get_bit(data[bit_index / 8], bit_index % 8);
            set_bit(&pixel->r, j, bit);

            bit_index++;
        }
    }
}

char *extract_data(const Image *image) {
    int data_length = 0;
    int bit_index = 0;
    char *data = malloc(1);

    for (int i = 0; i < image->width * image->height; i++) {
        const Pixel *pixel = &image->data[i];

        for (int j = 0; j < 3; j++) {
            if (bit_index >= data_length * 8) {
                data = realloc(data, data_length + 1);
                data[data_length] = '\0';
                return data;
            }

            unsigned char bit = get_bit(pixel->r, j);
            set_bit(&data[bit_index / 8], bit_index % 8, bit);

            bit_index++;
            data_length++;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    char *data = "Hello, world!";
    hide_data(image, data);

    write_image(argv[2], image);

    free(image->data);
    free(image);

    image = read_image(argv[2]);
    if (image == NULL) {
        return 1;
    }

    char *extracted_data = extract_data(image);
    if (extracted_data == NULL) {
        printf("Failed to extract data.\n");
        free(image->data);
        free(image);
        return 1;
    }

    printf("Extracted data: %s\n", extracted_data);
    free(extracted_data);
    free(image->data);
    free(image);

    return 0;
}