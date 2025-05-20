//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>
#include <time.h>

#define BIN_FILE "input.bin"
#define LINE_MAX 256

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

typedef struct {
    int width;
    int height;
    int size;
    pixel_t *pixels;
} image_t;

image_t load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("Error fstat");
        exit(EXIT_FAILURE);
    }

    image_t img;
    img.width = (int) (st.st_size / (3 * img.height));
    img.height = (int) (st.st_size / (img.width * 3));
    img.size = img.width * img.height * sizeof(pixel_t);

    img.pixels = mmap(NULL, img.size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    if (img.pixels == MAP_FAILED) {
        perror("Error mmap");
        exit(EXIT_FAILURE);
    }

    return img;
}

void save_binary(const char *filename, uint8_t *data, size_t size) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (write(fd, data, size) != size) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void binary_convert(image_t img) {
    clock_t start = clock();

    uint8_t *binary_data = malloc(img.size);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            pixel_t *px = &img.pixels[y * img.width + x];
            uint8_t byte = px->r;

            binary_data[y * img.width * 3 + x * 3] = byte;
            binary_data[y * img.width * 3 + x * 3 + 1] = byte >> 1;
            binary_data[y * img.width * 3 + x * 3 + 2] = byte >> 2;
        }
    }

    save_binary("output.bin", binary_data, img.size);

    free(binary_data);

    clock_t end = clock();
    printf("Binary conversion completed in %fs\n", (end - start) / CLOCKS_PER_SEC);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    image_t img = load_image(argv[1]);
    binary_convert(img);

    free(img.pixels);
    return EXIT_SUCCESS;
}