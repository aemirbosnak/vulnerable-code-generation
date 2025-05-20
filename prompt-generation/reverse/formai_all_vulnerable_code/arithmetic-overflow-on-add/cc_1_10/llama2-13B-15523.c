//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

#define WIDTH 800
#define HEIGHT 600
#define BUFFER_SIZE 4096

typedef struct {
    unsigned char *data;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    image_t *image = malloc(sizeof(image_t));
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open image file");
        return NULL;
    }

    struct stat stat;
    fstat(fd, &stat);
    image->width = stat.st_size / WIDTH * 3;
    image->height = stat.st_size / HEIGHT;
    image->data = mmap(NULL, stat.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("Failed to mmap image data");
        close(fd);
        return NULL;
    }

    close(fd);
    return image;
}

void save_image(image_t *image, const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Failed to open output file");
        return;
    }

    munmap(image->data, image->width * image->height * 3);
    write(fd, image->data, image->width * image->height * 3);
    close(fd);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2, int color) {
    int x, y, i;
    for (y = y1; y < y2; y++) {
        for (x = x1; x < x2; x++) {
            image->data[((y * image->width * 3) + (x * 3)) + 0] = color;
            image->data[((y * image->width * 3) + (x * 3)) + 1] = color;
            image->data[((y * image->width * 3) + (x * 3)) + 2] = color;
        }
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height, int color) {
    draw_line(image, x, y, x + width, y + height, color);
    draw_line(image, x, y + height, x + width, y, color);
    draw_line(image, x + width, y, x, y + height, color);
    draw_line(image, x + width, y + height, x, y, color);
}

void draw_circle(image_t *image, int x, int y, int radius, int color) {
    int x1, y1, x2, y2;
    for (x1 = x - radius; x1 <= x + radius; x1++) {
        for (y1 = y - radius; y1 <= y + radius; y1++) {
            int distance = sqrt((x1 - x)^2 + (y1 - y)^2);
            if (distance <= radius) {
                image->data[(((y1 * image->width * 3) + (x1 * 3)) + 0)] = color;
                image->data[(((y1 * image->width * 3) + (x1 * 3)) + 1)] = color;
                image->data[(((y1 * image->width * 3) + (x1 * 3)) + 2)] = color;
            }
        }
    }
}

void main() {
    image_t *image = load_image("image.jpg");
    if (image == NULL) {
        printf("Failed to load image\n");
        return;
    }

    int chosen_color = 0xFF0000; // Red
    int x = 100, y = 100, width = 200, height = 100;

    draw_rectangle(image, x, y, width, height, chosen_color);
    draw_circle(image, x, y, 50, chosen_color);

    save_image(image, "output.jpg");
}