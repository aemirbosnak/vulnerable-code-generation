//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <utime.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define IMAGE_FILE "image.bmp"

typedef struct {
    unsigned char *data;
    int width;
    int height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open image file");
        return NULL;
    }

    struct stat stat_info;
    if (fstat(fd, &stat_info) == -1) {
        perror("Failed to stat image file");
        close(fd);
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    image->data = mmap(NULL, stat_info.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("Failed to mmap image file");
        close(fd);
        return NULL;
    }

    image->width = stat_info.st_size / (WIDTH * BITS_PER_PIXEL);
    image->height = stat_info.st_size / (HEIGHT * BITS_PER_PIXEL);

    return image;
}

void save_image(const char *filename, image_t *image) {
    int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Failed to create image file");
        return;
    }

    if (ftruncate(fd, image->width * HEIGHT * BITS_PER_PIXEL) == -1) {
        perror("Failed to truncate image file");
        close(fd);
        return;
    }

    if (write(fd, image->data, image->width * HEIGHT * BITS_PER_PIXEL) != (ssize_t)image->width * HEIGHT * BITS_PER_PIXEL) {
        perror("Failed to write image data");
        close(fd);
        return;
    }

    close(fd);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = abs(dy) > abs(dx);
    int y = y1;

    if (steep) {
        dx = 0;
        dy = abs(dy);
    }

    for (int x = x1; x <= x2; x++) {
        image->data[y * image->width * BITS_PER_PIXEL + x * BITS_PER_PIXEL] =
                (dx < 0 ? 0 : (dx > 0 ? 255 : 0));
        if (steep) {
            y++;
        }
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    for (int yy = y; yy <= y + height; yy++) {
        for (int xx = x; xx <= x + width; xx++) {
            image->data[yy * image->width * BITS_PER_PIXEL + xx * BITS_PER_PIXEL] =
                    (xx < x + width && yy < y + height ? 255 : 0);
        }
    }
}

int main() {
    image_t *image = load_image(IMAGE_FILE);
    if (image == NULL) {
        perror("Failed to load image file");
        return 1;
    }

    draw_rectangle(image, 100, 100, 200, 100);
    draw_line(image, 100, 150, 300, 200);

    save_image("output.bmp", image);

    return 0;
}